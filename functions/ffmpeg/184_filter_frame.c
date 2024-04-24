static int filter_frame(AVFilterLink *inlink, AVFrame *frame)
{
    DrawBoxContext *s = inlink->dst->priv;
    const AVDetectionBBoxHeader *header = NULL;
    const AVDetectionBBox *bbox;
    AVFrameSideData *sd;
    int loop = 1;

    if (s->box_source == AV_FRAME_DATA_DETECTION_BBOXES) {
        sd = av_frame_get_side_data(frame, AV_FRAME_DATA_DETECTION_BBOXES);
        if (sd) {
            header = (AVDetectionBBoxHeader *)sd->data;
            loop = header->nb_bboxes;
        } else {
            av_log(s, AV_LOG_WARNING, "No detection bboxes.\n");
            return ff_filter_frame(inlink->dst->outputs[0], frame);
        }
    }

    for (int i = 0; i < loop; i++) {
        if (header) {
            bbox = av_get_detection_bbox(header, i);
            s->y = bbox->y;
            s->x = bbox->x;
            s->h = bbox->h;
            s->w = bbox->w;
        }

        s->draw_region(frame, s, FFMAX(s->x, 0), FFMAX(s->y, 0), FFMIN(s->x + s->w, frame->width),
                       FFMIN(s->y + s->h, frame->height), pixel_belongs_to_box);
    }

    return ff_filter_frame(inlink->dst->outputs[0], frame);
}