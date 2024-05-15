int _libssh2_hmac_update(libssh2_hmac_ctx *ctx,
                         const void *data, size_t datalen)
{
    char dummy[64];
    int len = (int) datalen;
    Qus_EC_t errcode;

    ctx->hash.Final_Op_Flag = Qc3_Continue;
    set_EC_length(errcode, sizeof(errcode));
    Qc3CalculateHMAC((char *) data, &len, Qc3_Data, (char *) &ctx->hash,
                     Qc3_Alg_Token, ctx->key.Key_Context_Token, Qc3_Key_Token,
                     anycsp, NULL, dummy, (char *) &errcode);
    return errcode.Bytes_Available? 0: 1;
}