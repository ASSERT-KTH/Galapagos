static int filter_frame(DBEDecodeContext *s, AVFrame *frame)
{
    const DolbyEHeaderInfo *const metadata = &s->dectx.metadata;
    const uint8_t *reorder;
    int ch, ret;

    if (metadata->nb_channels == 4)
        reorder = ch_reorder_4;
    else if (metadata->nb_channels == 6)
        reorder = ch_reorder_6;
    else if (metadata->nb_programs == 1 && metadata->output_channel_order == CHANNEL_ORDER_DEFAULT)
        reorder = ch_reorder_8;
    else
        reorder = ch_reorder_n;

    frame->nb_samples = FRAME_SAMPLES;
    if ((ret = ff_get_buffer(s->avctx, frame, 0)) < 0)
        return ret;

    for (ch = 0; ch < metadata->nb_channels; ch++) {
        float *output = (float *)frame->extended_data[reorder[ch]];
        transform(s, &s->channels[0][ch], s->history[ch], output);
        transform(s, &s->channels[1][ch], s->history[ch], output + FRAME_SAMPLES / 2);
        apply_gain(s, metadata->begin_gain[ch], metadata->end_gain[ch], output);
    }

    return 0;
}