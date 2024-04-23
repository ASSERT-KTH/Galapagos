static int FUNC(quant_matrix_extension)(CodedBitstreamContext *ctx, RWContext *rw,
                                        MPEG2RawQuantMatrixExtension *current)
{
    int err, i;

    HEADER("Quant Matrix Extension");

    ui(1, load_intra_quantiser_matrix);
    if (current->load_intra_quantiser_matrix) {
        for (i = 0; i < 64; i++)
            uirs(8, intra_quantiser_matrix[i], 1, i);
    }

    ui(1, load_non_intra_quantiser_matrix);
    if (current->load_non_intra_quantiser_matrix) {
        for (i = 0; i < 64; i++)
            uirs(8, non_intra_quantiser_matrix[i], 1, i);
    }

    ui(1, load_chroma_intra_quantiser_matrix);
    if (current->load_chroma_intra_quantiser_matrix) {
        for (i = 0; i < 64; i++)
            uirs(8, intra_quantiser_matrix[i], 1, i);
    }

    ui(1, load_chroma_non_intra_quantiser_matrix);
    if (current->load_chroma_non_intra_quantiser_matrix) {
        for (i = 0; i < 64; i++)
            uirs(8, chroma_non_intra_quantiser_matrix[i], 1, i);
    }

    return 0;
}