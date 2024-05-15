krb5_ser_unpack_int32(krb5_int32 *intp, krb5_octet **bufp, size_t *remainp)
{
    if (*remainp >= sizeof(krb5_int32)) {
        *intp = load_32_be(*bufp);
        *bufp += sizeof(krb5_int32);
        *remainp -= sizeof(krb5_int32);
        return(0);
    }
    else
        return(ENOMEM);
}