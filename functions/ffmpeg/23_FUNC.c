static int FUNC(sps_range_extension)(CodedBitstreamContext *ctx, RWContext *rw,
                                     H266RawSPS *current)
{
    int err;

    flag(sps_extended_precision_flag);
    if (current->sps_transform_skip_enabled_flag)
        flag(sps_ts_residual_coding_rice_present_in_sh_flag);
    else
        infer(sps_ts_residual_coding_rice_present_in_sh_flag, 0);
    flag(sps_rrc_rice_extension_flag);
    flag(sps_persistent_rice_adaptation_enabled_flag);
    flag(sps_reverse_last_sig_coeff_enabled_flag);

    return 0;
}