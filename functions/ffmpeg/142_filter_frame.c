static int filter_frame(AVFilterLink *outlink, AVFrame *buf)
{
    AVFilterContext *ctx = outlink->src;
    ChannelSplitContext *s = ctx->priv;
    const int i = FF_OUTLINK_IDX(outlink);
    enum AVChannel channel = av_channel_layout_channel_from_index(&buf->ch_layout, s->map[i]);
    int ret;

    AVFrame *buf_out = av_frame_clone(buf);
    if (!buf_out)
        return AVERROR(ENOMEM);

    buf_out->data[0] = buf_out->extended_data[0] = buf_out->extended_data[s->map[i]];
    ret = av_channel_layout_from_mask(&buf_out->ch_layout, 1ULL << channel);
    if (ret < 0)
        return ret;
#if FF_API_OLD_CHANNEL_LAYOUT
FF_DISABLE_DEPRECATION_WARNINGS
    buf_out->channel_layout =
        av_channel_layout_extract_channel(buf->channel_layout, s->map[i]);
    buf_out->channels = 1;
FF_ENABLE_DEPRECATION_WARNINGS
#endif

    return ff_filter_frame(ctx->outputs[i], buf_out);
}