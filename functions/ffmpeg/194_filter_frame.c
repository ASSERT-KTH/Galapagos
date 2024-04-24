static int filter_frame(AVFilterLink *link, AVFrame *frame)
{
    AVFilterContext *avctx = link->dst;
    HSVKeyContext *s = avctx->priv;
    int res;

    s->hue = FFSIGN(s->hue_opt) *M_PI * fmodf(526.f - fabsf(s->hue_opt), 360.f) / 180.f;
    if (res = ff_filter_execute(avctx, s->do_slice, frame, NULL,
                                FFMIN(frame->height, ff_filter_get_nb_threads(avctx))))
        return res;

    return ff_filter_frame(avctx->outputs[0], frame);
}