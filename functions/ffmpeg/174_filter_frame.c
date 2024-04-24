static int filter_frame(AVFilterLink *inlink, AVFrame *frame)
{
    AVFilterContext *ctx = inlink->dst;
    ColorCorrectContext *s = ctx->priv;
    const int nb_threads = s->analyze == MEDIAN ? 1 : FFMIN(s->planeheight[1], ff_filter_get_nb_threads(ctx));

    if (s->analyze) {
        const int nb_athreads = s->analyze == MEDIAN ? 1 : nb_threads;
        float bl = 0.f, rl = 0.f, bh = 0.f, rh = 0.f;

        ff_filter_execute(ctx, s->do_analyze, frame, NULL, nb_athreads);

        for (int i = 0; i < nb_athreads; i++) {
            bl += s->analyzeret[i][0];
            rl += s->analyzeret[i][1];
            bh += s->analyzeret[i][2];
            rh += s->analyzeret[i][3];
        }

        bl /= nb_athreads;
        rl /= nb_athreads;
        bh /= nb_athreads;
        rh /= nb_athreads;

        s->bl = -bl;
        s->rl = -rl;
        s->bh = -bh;
        s->rh = -rh;
    }

    ff_filter_execute(ctx, s->do_slice, frame, NULL, nb_threads);

    return ff_filter_frame(ctx->outputs[0], frame);
}