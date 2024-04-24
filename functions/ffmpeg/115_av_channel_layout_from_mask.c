int av_channel_layout_from_mask(AVChannelLayout *channel_layout,
                                uint64_t mask)
{
    if (!mask)
        return AVERROR(EINVAL);

    channel_layout->order       = AV_CHANNEL_ORDER_NATIVE;
    channel_layout->nb_channels = av_popcount64(mask);
    channel_layout->u.mask      = mask;

    return 0;
}