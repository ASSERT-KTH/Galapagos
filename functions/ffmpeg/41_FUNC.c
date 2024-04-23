static int FUNC(ols_timing_hrd_parameters) (CodedBitstreamContext *ctx,
                RWContext *rw, H266RawOlsTimingHrdParameters *current,
                uint8_t first_sublayer, uint8_t max_sublayers_minus1,
                const H266RawGeneralTimingHrdParameters *general)
{
    int err, i;
    for (i = first_sublayer; i <= max_sublayers_minus1; i++) {
        flags(fixed_pic_rate_general_flag[i], 1, i);
        if (!current->fixed_pic_rate_general_flag[i])
            flags(fixed_pic_rate_within_cvs_flag[i], 1, i);
        else
            infer(fixed_pic_rate_within_cvs_flag[i], 1);
        if (current->fixed_pic_rate_within_cvs_flag[i]) {
            ues(elemental_duration_in_tc_minus1[i], 0, 2047, 1, i);
            infer(low_delay_hrd_flag[i], 0);
        } else if ((general->general_nal_hrd_params_present_flag ||
                    general->general_vcl_hrd_params_present_flag) &&
                   general->hrd_cpb_cnt_minus1 == 0) {
            flags(low_delay_hrd_flag[i], 1, i);
        } else {
            infer(low_delay_hrd_flag[i], 0);
        }
        if (general->general_nal_hrd_params_present_flag)
            CHECK(FUNC(sublayer_hrd_parameters) (ctx, rw,
                                        &current->nal_sub_layer_hrd_parameters,
                                        i, general));
        if (general->general_vcl_hrd_params_present_flag)
            CHECK(FUNC(sublayer_hrd_parameters) (ctx, rw,
                                        &current->nal_sub_layer_hrd_parameters,
                                        i, general));
    }
    return 0;
}