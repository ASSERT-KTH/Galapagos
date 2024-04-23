static int FUNC(aud) (CodedBitstreamContext *ctx, RWContext *rw,
                     H266RawAUD *current)
{
    int err;

    HEADER("Access Unit Delimiter");

    CHECK(FUNC(nal_unit_header) (ctx, rw,
                                 &current->nal_unit_header, VVC_AUD_NUT));

    flag(aud_irap_or_gdr_flag);
    u(3, aud_pic_type, 0, 2);

    CHECK(FUNC(rbsp_trailing_bits) (ctx, rw));
    return 0;
}