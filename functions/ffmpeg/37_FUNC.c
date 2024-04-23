static int FUNC(dpb_parameters) (CodedBitstreamContext *ctx, RWContext *rw,
                                 H266DpbParameters *current,
                                 uint8_t max_sublayers_minus1,
                                 uint8_t sublayer_info_flag)
{
    int err, i;
    for (i = (sublayer_info_flag ? 0 : max_sublayers_minus1);
         i <= max_sublayers_minus1; i++) {
        ues(dpb_max_dec_pic_buffering_minus1[i], 0, VVC_MAX_DPB_SIZE - 1, 1, i);
        ues(dpb_max_num_reorder_pics[i],
            0, current->dpb_max_dec_pic_buffering_minus1[i], 1, i);
        ues(dpb_max_latency_increase_plus1[i], 0, UINT32_MAX - 1, 1, i);
    }
    return 0;
}