k5_der_get_value(struct k5input *in, uint8_t idbyte,
                 struct k5input *contents_out)
{
    uint8_t lenbyte, i;
    size_t len;
    const void *bytes;

    /* Do nothing if in is empty or the next byte doesn't match idbyte. */
    if (in->status || in->len == 0 || *in->ptr != idbyte)
        return false;

    /* Advance past the identifier byte and decode the length. */
    (void)k5_input_get_byte(in);
    lenbyte = k5_input_get_byte(in);
    if (lenbyte < 128) {
        len = lenbyte;
    } else {
        len = 0;
        for (i = 0; i < (lenbyte & 0x7F); i++) {
            if (len > (SIZE_MAX >> 8)) {
                k5_input_set_status(in, EOVERFLOW);
                return false;
            }
            len = (len << 8) | k5_input_get_byte(in);
        }
    }

    bytes = k5_input_get_bytes(in, len);
    if (bytes == NULL)
        return false;
    k5_input_init(contents_out, bytes, len);
    return true;
}