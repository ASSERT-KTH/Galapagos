static int filter_frame(AVFilterLink *inlink, AVFrame *frame)
{
    AVFilterContext *ctx = inlink->dst;
    ASetRateContext *sr = ctx->priv;
    AVFilterLink *outlink = ctx->outputs[0];

    frame->sample_rate = outlink->sample_rate;
    if (sr->rescale_pts)
        frame->pts = av_rescale(frame->pts, inlink->sample_rate,
                                           outlink->sample_rate);
    return ff_filter_frame(outlink, frame);
}