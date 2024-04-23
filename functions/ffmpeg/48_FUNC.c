static int FUNC(picture_display_extension)(CodedBitstreamContext *ctx, RWContext *rw,
                                           MPEG2RawPictureDisplayExtension *current)
{
    CodedBitstreamMPEG2Context *mpeg2 = ctx->priv_data;
    int err, i;

    HEADER("Picture Display Extension");

    for (i = 0; i < mpeg2->number_of_frame_centre_offsets; i++) {
        sis(16, frame_centre_horizontal_offset[i], 1, i);
        marker_bit();
        sis(16, frame_centre_vertical_offset[i],   1, i);
        marker_bit();
    }

    return 0;
}