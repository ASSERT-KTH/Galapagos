static int FUNC(extra_information)(CodedBitstreamContext *ctx, RWContext *rw,
                                   MPEG2RawExtraInformation *current,
                                   const char *element_name, const char *marker_name)
{
    int err;
    size_t k;
#ifdef READ
    GetBitContext start = *rw;
    uint8_t bit;

    for (k = 0; nextbits(1, 1, bit); k++)
        skip_bits(rw, 1 + 8);
    current->extra_information_length = k;
    if (k > 0) {
        *rw = start;
        current->extra_information_ref =
            av_buffer_allocz(k + AV_INPUT_BUFFER_PADDING_SIZE);
        if (!current->extra_information_ref)
            return AVERROR(ENOMEM);
        current->extra_information = current->extra_information_ref->data;
    }
#endif

    for (k = 0; k < current->extra_information_length; k++) {
        bit(marker_name, 1);
        xuia(8, element_name,
             current->extra_information[k], 0, 255, 1, k);
    }

    bit(marker_name, 0);

    return 0;
}