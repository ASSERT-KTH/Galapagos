static int FUNC(sei_decoded_picture_hash) (CodedBitstreamContext *ctx,
                                           RWContext *rw,
                                           H266RawSEIDecodedPictureHash *
                                           current)
{
    int err, c_idx, i;

    HEADER("Decoded Picture Hash");

    u(8, dph_sei_hash_type, 0, 2);
    flag(dph_sei_single_component_flag);
    ub(7, dph_sei_reserved_zero_7bits);

    for (c_idx = 0; c_idx < (current->dph_sei_single_component_flag ? 1 : 3);
         c_idx++) {
        if (current->dph_sei_hash_type == 0) {
            for (i = 0; i < 16; i++)
                us(8, dph_sei_picture_md5[c_idx][i], 0x00, 0xff, 2, c_idx, i);
        } else if (current->dph_sei_hash_type == 1) {
            us(16, dph_sei_picture_crc[c_idx], 0x0000, 0xffff, 1, c_idx);
        } else if (current->dph_sei_hash_type == 2) {
            us(32, dph_sei_picture_checksum[c_idx], 0x00000000, 0xffffffff, 1,
               c_idx);
        }
    }
    return 0;
}