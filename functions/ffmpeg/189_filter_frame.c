static int filter_frame(AVFilterLink *inlink, AVFrame *frame)
{
    FillBordersContext *s = inlink->dst->priv;

    s->fillborders(s, frame);

    return ff_filter_frame(inlink->dst->outputs[0], frame);
}