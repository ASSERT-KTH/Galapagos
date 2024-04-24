static int filter_frame(AVFilterLink *inlink, AVFrame *buf)
{
    AVFilterContext *ctx = inlink->dst;
    AudioNEqualizerContext *s = ctx->priv;
    AVFilterLink *outlink = ctx->outputs[0];

    if (!ctx->is_disabled)
        ff_filter_execute(ctx, filter_channels, buf, NULL,
                          FFMIN(inlink->ch_layout.nb_channels, ff_filter_get_nb_threads(ctx)));

    if (s->draw_curves) {
        AVFrame *clone;

        const int64_t pts = buf->pts +
            av_rescale_q(buf->nb_samples, (AVRational){ 1, inlink->sample_rate },
                         outlink->time_base);
        int ret;

        s->video->pts = pts;
        clone = av_frame_clone(s->video);
        if (!clone)
            return AVERROR(ENOMEM);
        ret = ff_filter_frame(ctx->outputs[1], clone);
        if (ret < 0)
            return ret;
    }

    return ff_filter_frame(outlink, buf);
}