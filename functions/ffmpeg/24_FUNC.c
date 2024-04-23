static int FUNC(profile_tier_level) (CodedBitstreamContext *ctx,
                                     RWContext *rw,
                                     H266RawProfileTierLevel *current,
                                     int profile_tier_present_flag,
                                     int max_num_sub_layers_minus1)
{
    int err, i;

    if (profile_tier_present_flag) {
        ub(7, general_profile_idc);
        flag(general_tier_flag);
    }
    ub(8, general_level_idc);
    flag(ptl_frame_only_constraint_flag);
    flag(ptl_multilayer_enabled_flag);
    if (profile_tier_present_flag) {
        CHECK(FUNC(general_constraints_info) (ctx, rw,
                                              &current->
                                              general_constraints_info));
    }
    for (i = max_num_sub_layers_minus1 - 1; i >= 0; i--)
        flags(ptl_sublayer_level_present_flag[i], 1, i);
    while (byte_alignment(rw) != 0)
        flag(ptl_reserved_zero_bit);
    for (i = max_num_sub_layers_minus1 - 1; i >= 0; i--)
        if (current->ptl_sublayer_level_present_flag[i])
            ubs(8, sublayer_level_idc[i], 1, i);
    if (profile_tier_present_flag) {
        ub(8, ptl_num_sub_profiles);
        for (i = 0; i < current->ptl_num_sub_profiles; i++)
            ubs(32, general_sub_profile_idc[i], 1, i);
    }
    return 0;
}