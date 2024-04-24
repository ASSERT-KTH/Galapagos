static int filter_frame(AVFilterLink *link, AVFrame *frame)
{
    AVFilterContext *avctx = link->dst;
    BackgroundkeyContext *s = avctx->priv;
    int64_t sum = 0;
    int ret = 0;

    if (!s->background) {
        s->background = ff_get_video_buffer(link, frame->width, frame->height);
        if (!s->background) {
            ret = AVERROR(ENOMEM);
            goto fail;
        }
        ret = av_frame_copy(s->background, frame);
        if (ret < 0)
            goto fail;
    }

    if (ret = ff_filter_execute(avctx, s->do_slice, frame, NULL,
                                FFMIN(frame->height, s->nb_threads)))
        goto fail;

    for (int n = 0; n < s->nb_threads; n++)
        sum += s->sums[n];
    if (s->max_sum * s->threshold < sum) {
        ret = av_frame_copy(s->background, frame);
        if (ret < 0)
            goto fail;
    }

    return ff_filter_frame(avctx->outputs[0], frame);
fail:
    av_frame_free(&frame);
    return ret;
}