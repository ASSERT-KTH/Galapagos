static int filter_frame(AVFilterLink *inlink, AVFrame *frame)
{
    CCRepackContext *ctx = inlink->dst->priv;
    AVFilterLink *outlink = inlink->dst->outputs[0];

    ff_ccfifo_extract(&ctx->cc_fifo, frame);
    ff_ccfifo_inject(&ctx->cc_fifo, frame);

    return ff_filter_frame(outlink, frame);
}