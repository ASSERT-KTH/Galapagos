static int FUNC(vui_payload) (CodedBitstreamContext *ctx, RWContext *rw,
                              H266RawVUI *current, uint16_t vui_payload_size,
                              uint8_t chroma_format_idc)
{
    int err;
    int start_position, current_position;

    start_position = bit_position(rw);
    CHECK(FUNC(vui_parameters) (ctx, rw, current, chroma_format_idc));
    current_position = bit_position(rw) - start_position;

    if (current_position < 8 * vui_payload_size) {
        CHECK(FUNC(payload_extension) (ctx, rw, &current->extension_data,
                                       vui_payload_size, current_position));
        fixed(1, vui_payload_bit_equal_to_one, 1);
        while (byte_alignment(rw) != 0)
            fixed(1, vui_payload_bit_equal_to_zero, 0);
    }
    return 0;
}