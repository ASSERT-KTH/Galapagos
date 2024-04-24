static int filter_frame(AVFilterLink *link, AVFrame *frame)
{
    AVFilterContext *ctx = link->dst;
    int ret;

    if (ret = ff_filter_execute(ctx, do_despill_slice, frame, NULL,
                                FFMIN(frame->height, ff_filter_get_nb_threads(ctx))))
        return ret;

    return ff_filter_frame(ctx->outputs[0], frame);
}