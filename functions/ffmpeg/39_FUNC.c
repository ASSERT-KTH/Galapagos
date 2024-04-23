static int FUNC(general_timing_hrd_parameters)(CodedBitstreamContext *ctx,
                                    RWContext *rw,
                                    H266RawGeneralTimingHrdParameters *current)
{
    int err;
    ub(32, num_units_in_tick);
    u(32, time_scale, 1, MAX_UINT_BITS(32));
    flag(general_nal_hrd_params_present_flag);
    flag(general_vcl_hrd_params_present_flag);

    if (current->general_nal_hrd_params_present_flag ||
        current->general_vcl_hrd_params_present_flag) {
        flag(general_same_pic_timing_in_all_ols_flag);
        flag(general_du_hrd_params_present_flag);
        if (current->general_du_hrd_params_present_flag)
            ub(8, tick_divisor_minus2);
        ub(4, bit_rate_scale);
        ub(4, cpb_size_scale);
        if (current->general_du_hrd_params_present_flag)
            ub(4, cpb_size_du_scale);
        ue(hrd_cpb_cnt_minus1, 0, 31);
    } else {
        //infer general_same_pic_timing_in_all_ols_flag?
        infer(general_du_hrd_params_present_flag, 0);
    }
    return 0;
}