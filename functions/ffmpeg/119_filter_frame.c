static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    AVFilterContext *ctx = inlink->dst;
    AVFilterLink *outlink = ctx->outputs[0];
    AudioContrastContext *s = ctx->priv;
    AVFrame *out;

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

    s->filter((void **)out->extended_data, (const void **)in->extended_data,
              in->nb_samples, in->ch_layout.nb_channels, s->contrast / 750);

    if (out != in)
        av_frame_free(&in);

    return ff_filter_frame(outlink, out);
}