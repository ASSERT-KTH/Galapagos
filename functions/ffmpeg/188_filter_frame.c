static int filter_frame(AVFilterLink *inlink, AVFrame *inpicref)
{
    FieldContext *field = inlink->dst->priv;
    AVFilterLink *outlink = inlink->dst->outputs[0];
    int i;

    inpicref->height = outlink->h;
#if FF_API_INTERLACED_FRAME
FF_DISABLE_DEPRECATION_WARNINGS
    inpicref->interlaced_frame = 0;
FF_ENABLE_DEPRECATION_WARNINGS
#endif
    inpicref->flags &= ~AV_FRAME_FLAG_INTERLACED;

    for (i = 0; i < field->nb_planes; i++) {
        if (field->type == FIELD_TYPE_BOTTOM)
            inpicref->data[i] = inpicref->data[i] + inpicref->linesize[i];
        inpicref->linesize[i] = 2 * inpicref->linesize[i];
    }
    return ff_filter_frame(outlink, inpicref);
}