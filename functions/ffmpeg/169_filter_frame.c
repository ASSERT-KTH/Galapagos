static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    AVFilterContext *ctx = inlink->dst;
    AVFilterLink *outlink = ctx->outputs[0];
    ChromaShiftContext *s = ctx->priv;
    AVFrame *out;

    out = ff_get_video_buffer(outlink, outlink->w, outlink->h);
    if (!out) {
        av_frame_free(&in);
        return AVERROR(ENOMEM);
    }
    av_frame_copy_props(out, in);

    s->in = in;
    if (!s->is_rgbashift) {
        av_image_copy_plane(out->data[0],
                            out->linesize[0],
                            in->data[0], in->linesize[0],
                            s->linesize[0], s->height[0]);
    }
    ff_filter_execute(ctx, s->filter_slice[s->edge], out, NULL,
                      FFMIN3(s->height[1],
                             s->height[2],
                             ff_filter_get_nb_threads(ctx)));
    s->in = NULL;
    av_frame_free(&in);
    return ff_filter_frame(outlink, out);
}