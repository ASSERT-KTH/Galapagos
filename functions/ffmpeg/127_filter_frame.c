static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    AVFilterContext *ctx = inlink->dst;
    AVFilterLink *outlink = ctx->outputs[0];
    AFreqShift *s = ctx->priv;
    AVFrame *out;
    ThreadData td;

    if (s->old_nb_coeffs != s->nb_coeffs)
        compute_coefs(s->cd, s->cf, s->nb_coeffs * 2, 2. * 20. / inlink->sample_rate);
    s->old_nb_coeffs = s->nb_coeffs;

    if (av_frame_is_writable(in)) {
        out = in;
    } else {
        out = ff_get_audio_buffer(outlink, in->nb_samples);
        if (!out) {
            av_frame_free(&in);
            return AVERROR(ENOMEM);
        }
        av_frame_copy_props(out, in);
    }

    td.in = in; td.out = out;
    ff_filter_execute(ctx, filter_channels, &td, NULL,
                      FFMIN(inlink->ch_layout.nb_channels, ff_filter_get_nb_threads(ctx)));

    s->in_samples += in->nb_samples;

    if (out != in)
        av_frame_free(&in);
    return ff_filter_frame(outlink, out);
}