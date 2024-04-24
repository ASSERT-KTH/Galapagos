static int filter_frame(AVFilterLink *inlink, AVFrame *frame)
{
    AVFilterContext *ctx = inlink->dst;
    HueSaturationContext *s = ctx->priv;

    init_matrix(s);

    ff_filter_execute(ctx, s->do_slice[(s->strength >= 99.f) && (s->colors == ALL)], frame, NULL,
                      FFMIN(s->planeheight[1], ff_filter_get_nb_threads(ctx)));

    return ff_filter_frame(ctx->outputs[0], frame);
}