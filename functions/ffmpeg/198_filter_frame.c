static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    AVFilterContext *ctx = inlink->dst;
    OCVContext *s = ctx->priv;
    AVFilterLink *outlink= inlink->dst->outputs[0];
    AVFrame *out;
    IplImage inimg, outimg;

    out = ff_get_video_buffer(outlink, outlink->w, outlink->h);
    if (!out) {
        av_frame_free(&in);
        return AVERROR(ENOMEM);
    }
    av_frame_copy_props(out, in);

    fill_iplimage_from_frame(&inimg , in , inlink->format);
    fill_iplimage_from_frame(&outimg, out, inlink->format);
    s->end_frame_filter(ctx, &inimg, &outimg);
    fill_frame_from_iplimage(out, &outimg, inlink->format);

    av_frame_free(&in);

    return ff_filter_frame(outlink, out);
}