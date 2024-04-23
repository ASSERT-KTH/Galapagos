static int FUNC(sei) (CodedBitstreamContext *ctx, RWContext *rw,
                      H266RawSEI *current, int prefix)
{
    int err;

    if (prefix)
        HEADER("Prefix Supplemental Enhancement Information");
    else
        HEADER("Suffix Supplemental Enhancement Information");

    CHECK(FUNC(nal_unit_header) (ctx, rw, &current->nal_unit_header,
                                 prefix ? VVC_PREFIX_SEI_NUT
                                 : VVC_SUFFIX_SEI_NUT));

    CHECK(FUNC_SEI(message_list) (ctx, rw, &current->message_list, prefix));

    CHECK(FUNC(rbsp_trailing_bits) (ctx, rw));

    return 0;
}