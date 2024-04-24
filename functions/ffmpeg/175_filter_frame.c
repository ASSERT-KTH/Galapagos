static int filter_frame(AVFilterLink *inlink, AVFrame *frame)
{
    AVFilterContext *ctx = inlink->dst;
    ColorizeContext *s = ctx->priv;
    float c[3];

    hsl2rgb(s->hue, s->saturation, s->lightness, &c[0], &c[1], &c[2]);
    rgb2yuv(c[0], c[1], c[2], &s->c[0], &s->c[1], &s->c[2], s->depth);

    ff_filter_execute(ctx, do_slice, frame, NULL,
                      FFMIN(s->planeheight[1], ff_filter_get_nb_threads(ctx)));

    return ff_filter_frame(ctx->outputs[0], frame);
}