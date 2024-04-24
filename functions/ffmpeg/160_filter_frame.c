static int filter_frame(AVFilterLink *inlink, AVFrame *frame)
{
    AVFilterContext *ctx = inlink->dst;
    AVFilterLink *outlink = ctx->outputs[0];

    frame->pts = rescale_pts(inlink, outlink, frame->pts);
    frame->duration = av_rescale_q(frame->duration, inlink->time_base, outlink->time_base);

    return ff_filter_frame(outlink, frame);
}