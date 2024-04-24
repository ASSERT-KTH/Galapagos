static int filter_frame(AVFilterLink *inlink, AVFrame *frame)
{
    AVFilterContext *ctx = inlink->dst;
    ColorTemperatureContext *s = ctx->priv;

    kelvin2rgb(s->temperature, s->color);

    ff_filter_execute(ctx, s->do_slice, frame, NULL,
                      FFMIN(frame->height, ff_filter_get_nb_threads(ctx)));

    return ff_filter_frame(ctx->outputs[0], frame);
}