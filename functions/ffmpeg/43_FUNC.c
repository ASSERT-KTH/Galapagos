static int FUNC(dci)(CodedBitstreamContext *ctx, RWContext *rw,
                     H266RawDCI *current)
{
    int err, i;

    HEADER("Decoding capability information");

    CHECK(FUNC(nal_unit_header)(ctx, rw,
                                &current->nal_unit_header, VVC_DCI_NUT));

    ub(4, dci_reserved_zero_4bits);
    ub(4, dci_num_ptls_minus1);
    for (i = 0; i <= current->dci_num_ptls_minus1; i++)
        CHECK(FUNC(profile_tier_level)(ctx, rw,
                                       current->dci_profile_tier_level + i, 1, 0));

    flag(dci_extension_flag);
    if (current->dci_extension_flag)
        CHECK(FUNC(extension_data)(ctx, rw, &current->extension_data));
    CHECK(FUNC(rbsp_trailing_bits)(ctx, rw));

    return 0;
}