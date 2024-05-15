int _libssh2_hmac_final(libssh2_hmac_ctx *ctx, void *out)
{
    char data;
    Qus_EC_t errcode;

    ctx->hash.Final_Op_Flag = Qc3_Final;
    set_EC_length(errcode, sizeof(errcode));
    Qc3CalculateHMAC((char *) data, &zero, Qc3_Data, (char *) &ctx->hash,
                     Qc3_Alg_Token, ctx->key.Key_Context_Token, Qc3_Key_Token,
                     anycsp, NULL, (char *) out, (char *) &errcode);
    return errcode.Bytes_Available? 0: 1;
}