static int FUNC(vui_parameters_default) (CodedBitstreamContext *ctx,
                                         RWContext *rw, H266RawVUI *current)
{
    //defined in D.8
    infer(vui_progressive_source_flag, 0);
    infer(vui_interlaced_source_flag, 0);

    infer(vui_non_packed_constraint_flag, 0);
    infer(vui_non_projected_constraint_flag, 0);

    infer(vui_aspect_ratio_constant_flag, 0);
    infer(vui_aspect_ratio_idc, 0);

    infer(vui_overscan_info_present_flag, 0);

    infer(vui_colour_primaries, 2);
    infer(vui_transfer_characteristics, 2);
    infer(vui_matrix_coeffs, 2);
    infer(vui_full_range_flag, 0);

    infer(vui_chroma_sample_loc_type_frame, 6);
    infer(vui_chroma_sample_loc_type_top_field, 6);
    infer(vui_chroma_sample_loc_type_bottom_field, 6);
    return 0;
}