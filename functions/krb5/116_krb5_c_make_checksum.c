krb5_c_make_checksum(krb5_context context, krb5_cksumtype cksumtype,
                     const krb5_keyblock *keyblock, krb5_keyusage usage,
                     const krb5_data *input, krb5_checksum *cksum)
{
    krb5_key key = NULL;
    krb5_error_code ret;

    if (keyblock != NULL) {
        ret = krb5_k_create_key(context, keyblock, &key);
        if (ret != 0)
            return ret;
    }
    ret = krb5_k_make_checksum(context, cksumtype, key, usage, input, cksum);
    krb5_k_free_key(context, key);
    return ret;
}