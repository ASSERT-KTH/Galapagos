static int filter_frame(AVFilterContext *ctx, AVFrame **out, AVFrame *in, AVFrame *ref)
{
    BM3DContext *s = ctx->priv;
    AVFilterLink *outlink = ctx->outputs[0];
    int p;

    *out = ff_get_video_buffer(outlink, outlink->w, outlink->h);
    if (!*out)
        return AVERROR(ENOMEM);
    av_frame_copy_props(*out, in);

    for (p = 0; p < s->nb_planes; p++) {
        const int nb_jobs = FFMAX(1, FFMIN(s->nb_threads, s->planeheight[p] / s->block_size));
        ThreadData td;

        if (!((1 << p) & s->planes) || ctx->is_disabled) {
            av_image_copy_plane((*out)->data[p], (*out)->linesize[p],
                                in->data[p], in->linesize[p],
                                s->planewidth[p] * (1 + (s->depth > 8)), s->planeheight[p]);
            continue;
        }

        td.src = in->data[p];
        td.src_linesize = in->linesize[p];
        td.ref = ref->data[p];
        td.ref_linesize = ref->linesize[p];
        td.plane = p;
        ff_filter_execute(ctx, filter_slice, &td, NULL, nb_jobs);

        s->do_output(s, (*out)->data[p], (*out)->linesize[p], p, nb_jobs);
    }

    return 0;
}