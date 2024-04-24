int ff_inlink_consume_frame(AVFilterLink *link, AVFrame **rframe)
{
    AVFrame *frame;

    *rframe = NULL;
    if (!ff_inlink_check_available_frame(link))
        return 0;

    if (link->fifo.samples_skipped) {
        frame = ff_framequeue_peek(&link->fifo, 0);
        return ff_inlink_consume_samples(link, frame->nb_samples, frame->nb_samples, rframe);
    }

    frame = ff_framequeue_take(&link->fifo);
    consume_update(link, frame);
    *rframe = frame;
    return 1;
}