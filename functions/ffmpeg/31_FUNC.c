static int FUNC(ph) (CodedBitstreamContext *ctx, RWContext *rw,
                     H266RawPH *current)
{
    int err;

    HEADER("Picture Header");

    CHECK(FUNC(nal_unit_header) (ctx, rw, &current->nal_unit_header, VVC_PH_NUT));
    CHECK(FUNC(picture_header) (ctx, rw, &current->ph_picture_header));
    CHECK(FUNC(rbsp_trailing_bits) (ctx, rw));
    return 0;
}