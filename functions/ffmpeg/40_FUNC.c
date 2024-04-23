static int FUNC(sublayer_hrd_parameters) (CodedBitstreamContext *ctx,
                              RWContext *rw,
                              H266RawSubLayerHRDParameters *current,
                              int sublayer_id,
                              const H266RawGeneralTimingHrdParameters *general)
{
    int err, i;
    for (i = 0; i <= general->hrd_cpb_cnt_minus1; i++) {
        ues(bit_rate_value_minus1[sublayer_id][i], 0, UINT32_MAX - 1, 2,
            sublayer_id, i);
        ues(cpb_size_value_minus1[sublayer_id][i], 0, UINT32_MAX - 1, 2,
            sublayer_id, i);
        if (general->general_du_hrd_params_present_flag) {
            ues(cpb_size_du_value_minus1[sublayer_id][i],
                0, UINT32_MAX - 1, 2, sublayer_id, i);
            ues(bit_rate_du_value_minus1[sublayer_id][i],
                0, UINT32_MAX - 1, 2, sublayer_id, i);
        }
        flags(cbr_flag[sublayer_id][i], 2, sublayer_id, i);
    }
    return 0;
}