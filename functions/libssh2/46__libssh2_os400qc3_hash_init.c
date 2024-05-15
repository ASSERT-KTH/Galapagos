_libssh2_os400qc3_hash_init(Qc3_Format_ALGD0100_T *x, unsigned int algorithm)
{
    Qc3_Format_ALGD0500_T algd;
    Qus_EC_t errcode;

    if(!x)
        return 0;

    memset((char *) x, 0, sizeof(*x));
    x->Final_Op_Flag = Qc3_Continue;
    algd.Hash_Alg = algorithm;
    set_EC_length(errcode, sizeof(errcode));
    Qc3CreateAlgorithmContext((char *) &algd, Qc3_Alg_Hash,
                              x->Alg_Context_Token, &errcode);
    return errcode.Bytes_Available? 0: 1;
}