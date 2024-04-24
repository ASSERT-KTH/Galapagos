static int filter_frame(AVFilterLink *inlink, AVFrame *frame)
{
    AVFilterContext *ctx = inlink->dst;
    SelectContext *select = ctx->priv;

    select_frame(ctx, frame);
    if (select->select)
        return ff_filter_frame(ctx->outputs[select->select_out], frame);

    av_frame_free(&frame);
    return 0;
}