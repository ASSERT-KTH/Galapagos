static int FUNC(lmcs_data)(CodedBitstreamContext *ctx, RWContext *rw,
                           H266RawAPS *current)
{
    int err, i, lmcs_max_bin_idx;

    ue(lmcs_min_bin_idx, 0, 15);
    ue(lmcs_delta_max_bin_idx, 0, 15);
    ue(lmcs_delta_cw_prec_minus1, 0, 14);

    lmcs_max_bin_idx = 15 - current->lmcs_delta_max_bin_idx;

    if (lmcs_max_bin_idx < current->lmcs_min_bin_idx)
        return AVERROR_INVALIDDATA;

    for (i = current->lmcs_min_bin_idx; i <= lmcs_max_bin_idx; i++) {
        ubs(current->lmcs_delta_cw_prec_minus1 + 1, lmcs_delta_abs_cw[i], 1, i);
        if (current->lmcs_delta_abs_cw[i] > 0)
            flags(lmcs_delta_sign_cw_flag[i], 1, i);
        else
            infer(lmcs_delta_sign_cw_flag[i], 0);
    }

    if (current->aps_chroma_present_flag) {
        ub(3, lmcs_delta_abs_crs);
        if (current->lmcs_delta_abs_crs > 0)
            flag(lmcs_delta_sign_crs_flag);
        else
            infer(lmcs_delta_sign_crs_flag, 0);
    } else {
        infer(lmcs_delta_abs_crs, 0);
        infer(lmcs_delta_sign_crs_flag, 0);
    }

    return 0;
}