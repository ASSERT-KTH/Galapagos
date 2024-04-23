static int FUNC(payload_extension) (CodedBitstreamContext *ctx, RWContext *rw,
                                    H266RawExtensionData *current,
                                    uint32_t payload_size, int cur_pos)
{
    int err;
    size_t byte_length, k;

#ifdef READ
    GetBitContext tmp;
    int bits_left, payload_zero_bits;

    if (!cbs_h265_payload_extension_present(rw, payload_size, cur_pos))
        return 0;

    bits_left = 8 * payload_size - cur_pos;
    tmp = *rw;
    if (bits_left > 8)
        skip_bits_long(&tmp, bits_left - 8);
    payload_zero_bits = get_bits(&tmp, FFMIN(bits_left, 8));
    if (!payload_zero_bits)
        return AVERROR_INVALIDDATA;
    payload_zero_bits = ff_ctz(payload_zero_bits);
    current->bit_length = bits_left - payload_zero_bits - 1;
    allocate(current->data, (current->bit_length + 7) / 8);
#endif

    byte_length = (current->bit_length + 7) / 8;
    for (k = 0; k < byte_length; k++) {
        int length = FFMIN(current->bit_length - k * 8, 8);
        xu(length, reserved_payload_extension_data, current->data[k],
           0, MAX_UINT_BITS(length), 0);
    }

    return 0;
}