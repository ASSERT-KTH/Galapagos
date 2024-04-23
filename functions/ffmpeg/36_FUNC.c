static int FUNC(extension_data) (CodedBitstreamContext *ctx, RWContext *rw,
                                 H266RawExtensionData *current)
{
    int err;
    size_t k;
#ifdef READ
    GetBitContext start;
    uint8_t bit;
    start = *rw;
    for (k = 0; cbs_h2645_read_more_rbsp_data(rw); k++)
        skip_bits(rw, 1);
    current->bit_length = k;
    if (k > 0) {
        *rw = start;
        allocate(current->data, (current->bit_length + 7) / 8);
        for (k = 0; k < current->bit_length; k++) {
            xu(1, extension_data, bit, 0, 1, 0);
            current->data[k / 8] |= bit << (7 - k % 8);
        }
    }
#else
    for (k = 0; k < current->bit_length; k++)
        xu(1, extension_data, current->data[k / 8] >> (7 - k % 8) & 1, 0, 1, 0);
#endif
    return 0;
}