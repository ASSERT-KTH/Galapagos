static int filter_frame(AVFilterLink *inlink, AVFrame *frame)
{
    int ret;
    AVFrame *out_frame;

    Bs2bContext     *bs2b = inlink->dst->priv;
    AVFilterLink *outlink = inlink->dst->outputs[0];

    if (av_frame_is_writable(frame)) {
        out_frame = frame;
    } else {
        out_frame = ff_get_audio_buffer(outlink, frame->nb_samples);
        if (!out_frame) {
            av_frame_free(&frame);
            return AVERROR(ENOMEM);
        }
        av_frame_copy(out_frame, frame);
        ret = av_frame_copy_props(out_frame, frame);
        if (ret < 0) {
            av_frame_free(&out_frame);
            av_frame_free(&frame);
            return ret;
        }
    }

    bs2b->filter(bs2b->bs2bp, out_frame->extended_data[0], out_frame->nb_samples);

    if (frame != out_frame)
        av_frame_free(&frame);

    return ff_filter_frame(outlink, out_frame);
}