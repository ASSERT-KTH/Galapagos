static int filter_frame(AVFilterLink *inlink, AVFrame *ref)
{
    FrameStepContext *framestep = inlink->dst->priv;

    if (!(inlink->frame_count_out % framestep->frame_step)) {
        return ff_filter_frame(inlink->dst->outputs[0], ref);
    } else {
        av_frame_free(&ref);
        return 0;
    }
}