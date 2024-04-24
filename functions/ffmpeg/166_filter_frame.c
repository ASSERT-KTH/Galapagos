static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    AVFilterContext *ctx = inlink->dst;
    AVFilterLink *outlink = ctx->outputs[0];
    CASContext *s = ctx->priv;
    AVFrame *out;

    out = ff_get_video_buffer(outlink, outlink->w, outlink->h);
    if (!out) {
        av_frame_free(&in);
        return AVERROR(ENOMEM);
    }
    av_frame_copy_props(out, in);

    s->in = in;
    ff_filter_execute(ctx, s->do_slice, out, NULL,
                      FFMIN(in->height, ff_filter_get_nb_threads(ctx)));
    av_frame_free(&in);
    s->in = NULL;

    return ff_filter_frame(ctx->outputs[0], out);
}