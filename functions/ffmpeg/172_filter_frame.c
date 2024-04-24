static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    AVFilterContext *ctx = inlink->dst;
    AVFilterLink *outlink = ctx->outputs[0];
    AVFrame *out;
    int ret;
    int direct = 0;

    ret = illumination_estimation(ctx, in);
    if (ret) {
        av_frame_free(&in);
        return ret;
    }

    if (av_frame_is_writable(in)) {
        direct = 1;
        out = in;
    } else {
        out = ff_get_video_buffer(outlink, outlink->w, outlink->h);
        if (!out) {
            av_frame_free(&in);
            return AVERROR(ENOMEM);
        }
        av_frame_copy_props(out, in);
    }
    chromatic_adaptation(ctx, in, out);

    if (!direct)
        av_frame_free(&in);

    return ff_filter_frame(outlink, out);
}