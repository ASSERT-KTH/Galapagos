static int filter_frame(AVFilterLink *link, AVFrame *frame)
{
    AVFilterContext *ctx = link->dst;
    ColorContrastContext *s = ctx->priv;
    int res;

    if (res = ff_filter_execute(ctx, s->do_slice, frame, NULL,
                                FFMIN(frame->height, ff_filter_get_nb_threads(ctx))))
        return res;

    return ff_filter_frame(ctx->outputs[0], frame);
}