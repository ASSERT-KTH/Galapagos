static int FUNC(extension_data)(CodedBitstreamContext *ctx, RWContext *rw,
                                MPEG2RawExtensionData *current)
{
    int err;

    HEADER("Extension Data");

    ui(8, extension_start_code);
    ui(4, extension_start_code_identifier);

    switch (current->extension_start_code_identifier) {
    case MPEG2_EXTENSION_SEQUENCE:
        return FUNC(sequence_extension)
            (ctx, rw, &current->data.sequence);
    case MPEG2_EXTENSION_SEQUENCE_DISPLAY:
        return FUNC(sequence_display_extension)
            (ctx, rw, &current->data.sequence_display);
    case MPEG2_EXTENSION_QUANT_MATRIX:
        return FUNC(quant_matrix_extension)
            (ctx, rw, &current->data.quant_matrix);
    case MPEG2_EXTENSION_PICTURE_DISPLAY:
        return FUNC(picture_display_extension)
            (ctx, rw, &current->data.picture_display);
    case MPEG2_EXTENSION_PICTURE_CODING:
        return FUNC(picture_coding_extension)
            (ctx, rw, &current->data.picture_coding);
    default:
        av_log(ctx->log_ctx, AV_LOG_ERROR, "Extension ID %d not supported.\n",
               current->extension_start_code_identifier);
        return AVERROR_PATCHWELCOME;
    }
}