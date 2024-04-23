static int FUNC(opi)(CodedBitstreamContext *ctx, RWContext *rw,
                     H266RawOPI *current)
{
    int err;

    HEADER("Operating point information");

    CHECK(FUNC(nal_unit_header)(ctx, rw,
                                &current->nal_unit_header, VVC_OPI_NUT));

    flag(opi_ols_info_present_flag);
    flag(opi_htid_info_present_flag);

    if(current->opi_ols_info_present_flag)
        ue(opi_ols_idx, 0, VVC_MAX_TOTAL_NUM_OLSS - 1);

    if(current->opi_htid_info_present_flag)
        ub(3, opi_htid_plus1);

    flag(opi_extension_flag);
    if (current->opi_extension_flag)
        CHECK(FUNC(extension_data) (ctx, rw, &current->extension_data));
    CHECK(FUNC(rbsp_trailing_bits) (ctx, rw));

    return 0;
}