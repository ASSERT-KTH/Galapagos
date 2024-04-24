static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    AVFilterContext *ctx = inlink->dst;
    AVFilterLink *outlink = ctx->outputs[0];
    AudioNLMeansContext *s = ctx->priv;
    AVFrame *out;

    if (av_frame_is_writable(in)) {
        out = in;
    } else {
        out = ff_get_audio_buffer(outlink, in->nb_samples);
        if (!out) {
            av_frame_free(&in);
            return AVERROR(ENOMEM);
        }

        out->pts = in->pts;
    }

    s->in = in;
    ff_filter_execute(ctx, filter_channel, out, NULL, inlink->ch_layout.nb_channels);

    if (out != in)
        av_frame_free(&in);
    return ff_filter_frame(outlink, out);
}