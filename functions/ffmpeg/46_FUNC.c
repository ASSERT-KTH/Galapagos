static int FUNC(picture_header)(CodedBitstreamContext *ctx, RWContext *rw,
                                MPEG2RawPictureHeader *current)
{
    int err;

    HEADER("Picture Header");

    ui(8,  picture_start_code);

    ui(10, temporal_reference);
    uir(3, picture_coding_type);
    ui(16, vbv_delay);

    if (current->picture_coding_type == 2 ||
        current->picture_coding_type == 3) {
        ui(1, full_pel_forward_vector);
        ui(3, forward_f_code);
    }

    if (current->picture_coding_type == 3) {
        ui(1, full_pel_backward_vector);
        ui(3, backward_f_code);
    }

    CHECK(FUNC(extra_information)(ctx, rw, &current->extra_information_picture,
                                  "extra_information_picture[k]", "extra_bit_picture"));

    return 0;
}