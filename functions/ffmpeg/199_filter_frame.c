static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    AVFilterContext *ctx = inlink->dst;
    LimiterContext *s = ctx->priv;
    AVFilterLink *outlink = ctx->outputs[0];
    ThreadData td;
    AVFrame *out;

    if (av_frame_is_writable(in)) {
        out = in;
    } else {
        out = ff_get_video_buffer(outlink, outlink->w, outlink->h);
        if (!out) {
            av_frame_free(&in);
            return AVERROR(ENOMEM);
        }
        av_frame_copy_props(out, in);
    }

    td.out = out;
    td.in = in;
    ff_filter_execute(ctx, filter_slice, &td, NULL,
                      FFMIN(s->height[2], ff_filter_get_nb_threads(ctx)));
    if (out != in)
        av_frame_free(&in);

    return ff_filter_frame(outlink, out);
}