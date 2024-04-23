static int FUNC(aps)(CodedBitstreamContext *ctx, RWContext *rw,
                     H266RawAPS *current, int prefix)
{
    int err;

    if (prefix)
        HEADER("Prefix Adaptation parameter set");
    else
        HEADER("Suffix Adaptation parameter set");

    CHECK(FUNC(nal_unit_header)(ctx, rw, &current->nal_unit_header,
                                prefix ? VVC_PREFIX_APS_NUT
                                       : VVC_SUFFIX_APS_NUT));

    ub(3, aps_params_type);
    ub(5, aps_adaptation_parameter_set_id);
    flag(aps_chroma_present_flag);
    if (current->aps_params_type == VVC_ASP_TYPE_ALF)
        CHECK(FUNC(alf_data)(ctx, rw, current));
    else if(current->aps_params_type == VVC_ASP_TYPE_LMCS)
        CHECK(FUNC(lmcs_data)(ctx, rw, current));
    else if (current->aps_params_type == VVC_ASP_TYPE_SCALING)
        CHECK(FUNC(scaling_list_data)(ctx, rw, current));
    flag(aps_extension_flag);
    if (current->aps_extension_flag)
        CHECK(FUNC(extension_data) (ctx, rw, &current->extension_data));
    CHECK(FUNC(rbsp_trailing_bits) (ctx, rw));

    return 0;
}