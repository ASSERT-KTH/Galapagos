av_cold int av_tx_init(AVTXContext **ctx, av_tx_fn *tx, enum AVTXType type,
                       int inv, int len, const void *scale, uint64_t flags)
{
    int ret;
    AVTXContext tmp = { 0 };
    const double default_scale_d = 1.0;
    const float  default_scale_f = 1.0f;

    if (!len || type >= AV_TX_NB || !ctx || !tx)
        return AVERROR(EINVAL);

    if (!(flags & AV_TX_UNALIGNED))
        flags |= FF_TX_ALIGNED;
    if (!(flags & AV_TX_INPLACE))
        flags |= FF_TX_OUT_OF_PLACE;

    if (!scale && ((type == AV_TX_FLOAT_MDCT) || (type == AV_TX_INT32_MDCT)))
        scale = &default_scale_f;
    else if (!scale && (type == AV_TX_DOUBLE_MDCT))
        scale = &default_scale_d;

    ret = ff_tx_init_subtx(&tmp, type, flags, NULL, len, inv, scale);
    if (ret < 0)
        return ret;

    *ctx = &tmp.sub[0];
    *tx  = tmp.fn[0];

#if !CONFIG_SMALL
    av_log(NULL, AV_LOG_DEBUG, "Transform tree:\n");
    print_tx_structure(*ctx, 0);
#endif

    return ret;
}