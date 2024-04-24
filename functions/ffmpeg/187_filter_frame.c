static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    AVFilterContext *ctx = inlink->dst;
    AVFilterLink *outlink = ctx->outputs[0];
    ExposureContext *s = ctx->priv;
    float diff = fabsf(exp2f(-s->exposure) - s->black);
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

    diff = diff > 0.f ? diff : 1.f / 1024.f;
    s->scale = 1.f / diff;
    td.out = out;
    td.in = in;
    ff_filter_execute(ctx, s->do_slice, &td, NULL,
                      FFMIN(out->height, ff_filter_get_nb_threads(ctx)));

    if (out != in)
        av_frame_free(&in);
    return ff_filter_frame(outlink, out);
}