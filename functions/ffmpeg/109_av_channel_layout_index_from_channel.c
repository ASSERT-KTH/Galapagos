int av_channel_layout_index_from_channel(const AVChannelLayout *channel_layout,
                                         enum AVChannel channel)
{
    int i;

    if (channel == AV_CHAN_NONE)
        return AVERROR(EINVAL);

    switch (channel_layout->order) {
    case AV_CHANNEL_ORDER_CUSTOM:
        for (i = 0; i < channel_layout->nb_channels; i++)
            if (channel_layout->u.map[i].id == channel)
                return i;
        return AVERROR(EINVAL);
    case AV_CHANNEL_ORDER_AMBISONIC:
    case AV_CHANNEL_ORDER_NATIVE: {
        uint64_t mask = channel_layout->u.mask;
        int ambi_channels = channel_layout->nb_channels - av_popcount64(mask);
        if (channel_layout->order == AV_CHANNEL_ORDER_AMBISONIC &&
            channel >= AV_CHAN_AMBISONIC_BASE) {
            if (channel - AV_CHAN_AMBISONIC_BASE >= ambi_channels)
                return AVERROR(EINVAL);
            return channel - AV_CHAN_AMBISONIC_BASE;
        }
        if ((unsigned)channel > 63 || !(mask & (1ULL << channel)))
            return AVERROR(EINVAL);
        mask &= (1ULL << channel) - 1;
        return av_popcount64(mask) + ambi_channels;
        }
    default:
        return AVERROR(EINVAL);
    }
}