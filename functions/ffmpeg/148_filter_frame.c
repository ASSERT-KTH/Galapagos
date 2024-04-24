static int filter_frame(AVFilterLink *inlink, AVFrame *insamples)
{
    int ret;
    int n = insamples->nb_samples;
    AVFilterLink *const outlink = inlink->dst->outputs[0];
    AVFrame *outsamples = ff_get_audio_buffer(outlink, n);
    PanContext *pan = inlink->dst->priv;

    if (!outsamples) {
        av_frame_free(&insamples);
        return AVERROR(ENOMEM);
    }
    swr_convert(pan->swr, outsamples->extended_data, n,
                (void *)insamples->extended_data, n);
    av_frame_copy_props(outsamples, insamples);
#if FF_API_OLD_CHANNEL_LAYOUT
FF_DISABLE_DEPRECATION_WARNINGS
    outsamples->channel_layout = outlink->channel_layout;
    outsamples->channels = outlink->ch_layout.nb_channels;
FF_ENABLE_DEPRECATION_WARNINGS
#endif
    if ((ret = av_channel_layout_copy(&outsamples->ch_layout, &outlink->ch_layout)) < 0) {
        av_frame_free(&outsamples);
        av_frame_free(&insamples);
        return ret;
    }

    av_frame_free(&insamples);
    return ff_filter_frame(outlink, outsamples);
}