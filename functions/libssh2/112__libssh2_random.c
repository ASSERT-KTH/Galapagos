_libssh2_random(unsigned char *buf, size_t len)
{
    Qus_EC_t errcode;

    set_EC_length(errcode, sizeof(errcode));
    Qc3GenPRNs(buf, len,
        Qc3PRN_TYPE_NORMAL, Qc3PRN_NO_PARITY, (char *) &errcode);
    return errcode.Bytes_Available? -1: 0;
}