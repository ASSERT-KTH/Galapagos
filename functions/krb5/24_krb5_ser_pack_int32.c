krb5_ser_pack_int32(krb5_int32 iarg, krb5_octet **bufp, size_t *remainp)
{
    if (*remainp >= sizeof(krb5_int32)) {
        store_32_be(iarg, *bufp);
        *bufp += sizeof(krb5_int32);
        *remainp -= sizeof(krb5_int32);
        return(0);
    }
    else
        return(ENOMEM);
}