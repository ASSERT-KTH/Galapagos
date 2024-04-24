 static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    AVFilterContext *ctx = inlink->dst;
    ESTDIFContext *s = ctx->priv;
    int ret;

    if (!s->prev) {
        s->prev = in;
        return 0;
    }

    if ((s->deint && !(s->prev->flags & AV_FRAME_FLAG_INTERLACED)) || ctx->is_disabled) {
        s->prev->pts *= 2;
        s->prev->duration *= 2;
        ret = ff_filter_frame(ctx->outputs[0], s->prev);
        s->prev = in;
        return ret;
    }

    ret = filter(ctx, s->prev, s->prev->pts * 2,
                 s->prev->duration * (s->mode ? 1 : 2));
    if (ret < 0 || s->mode == 0) {
        av_frame_free(&s->prev);
        s->prev = in;
        return ret;
    }

    ret = filter(ctx, s->prev, s->prev->pts + in->pts, in->duration);
    av_frame_free(&s->prev);
    s->prev = in;
    return ret;
}