static int filter_frame(AVFilterLink *inlink, AVFrame *frame)
{
    AVFilterContext *ctx = inlink->dst;
    AVFilterLink *outlink = ctx->outputs[0];
    SideDataContext *s = ctx->priv;
    AVFrameSideData *sd = NULL;

    if (s->type != -1)
       sd = av_frame_get_side_data(frame, s->type);

    switch (s->mode) {
    case SIDEDATA_SELECT:
        if (sd) {
            return ff_filter_frame(outlink, frame);
        }
        break;
    case SIDEDATA_DELETE:
        if (s->type == -1) {
            while (frame->nb_side_data)
                av_frame_remove_side_data(frame, frame->side_data[0]->type);
        } else if (sd) {
            av_frame_remove_side_data(frame, s->type);
        }
        return ff_filter_frame(outlink, frame);
        break;
    default:
        av_assert0(0);
    };

    av_frame_free(&frame);

    return 0;
}