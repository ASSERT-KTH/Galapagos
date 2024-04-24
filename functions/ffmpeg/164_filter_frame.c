static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    AVFilterContext *ctx = inlink->dst;
    BilateralContext *s = ctx->priv;
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

    td.in = in;
    td.out = out;
    ff_filter_execute(ctx, bilateralh_planes, &td, NULL, s->nb_threads);
    ff_filter_execute(ctx, bilateralv_planes, &td, NULL, s->nb_threads);
    ff_filter_execute(ctx, bilateralo_planes, &td, NULL, s->nb_threads);

    if (out != in)
        av_frame_free(&in);
    return ff_filter_frame(outlink, out);
}