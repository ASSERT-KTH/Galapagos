_libssh2_os400qc3_hash_update(Qc3_Format_ALGD0100_T *ctx,
                              const unsigned char *data, int len)
{
    char dummy[64];
    Qus_EC_t errcode;

    ctx->Final_Op_Flag = Qc3_Continue;
    set_EC_length(errcode, sizeof(errcode));
    Qc3CalculateHash((char *) data, &len, Qc3_Data, (char *) ctx,
                     Qc3_Alg_Token, anycsp, NULL, dummy, &errcode);
    return errcode.Bytes_Available? 0: 1;
}