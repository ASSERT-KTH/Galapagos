static int filter_frame(AVFilterLink *inlink, AVFrame *frame)
{
    AVFilterContext *ctx = inlink->dst;
    RealtimeContext *s = ctx->priv;

    if (frame->pts != AV_NOPTS_VALUE) {
        int64_t pts = av_rescale_q(frame->pts, inlink->time_base, AV_TIME_BASE_Q) / s->speed;
        int64_t now = av_gettime_relative();
        int64_t sleep = pts - now + s->delta;
        if (!s->inited) {
            s->inited = 1;
            sleep = 0;
            s->delta = now - pts;
        }
        if (FFABS(sleep) > s->limit / s->speed) {
            av_log(ctx, AV_LOG_WARNING,
                   "time discontinuity detected: %"PRIi64" us, resetting\n",
                   sleep);
            sleep = 0;
            s->delta = now - pts;
        }
        if (sleep > 0) {
            av_log(ctx, AV_LOG_DEBUG, "sleeping %"PRIi64" us\n", sleep);
            for (; sleep > 600000000; sleep -= 600000000)
                av_usleep(600000000);
            av_usleep(sleep);
        }
    }
    return ff_filter_frame(inlink->dst->outputs[0], frame);
}