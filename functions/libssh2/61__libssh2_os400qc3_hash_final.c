_libssh2_os400qc3_hash_final(Qc3_Format_ALGD0100_T *ctx, unsigned char *out)
{
    char data;
    Qus_EC_t errcode;

    ctx->Final_Op_Flag = Qc3_Final;
    set_EC_length(errcode, sizeof(errcode));
    Qc3CalculateHash(&data, &zero, Qc3_Data, (char *) ctx, Qc3_Alg_Token,
                     anycsp, NULL, (char *) out, &errcode);
    Qc3DestroyAlgorithmContext(ctx->Alg_Context_Token, (char *) &ecnull);
    memset(ctx->Alg_Context_Token, 0, sizeof(ctx->Alg_Context_Token));
    return errcode.Bytes_Available? 0: 1;
}