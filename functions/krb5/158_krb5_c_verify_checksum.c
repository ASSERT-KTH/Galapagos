krb5_c_verify_checksum(krb5_context context, const krb5_keyblock *keyblock,
                       krb5_keyusage usage, const krb5_data *data,
                       const krb5_checksum *cksum, krb5_boolean *valid)
{
    krb5_key key = NULL;
    krb5_error_code ret;

    if (keyblock != NULL) {
        ret = krb5_k_create_key(context, keyblock, &key);
        if (ret != 0)
            return ret;
    }
    ret = krb5_k_verify_checksum(context, key, usage, data, cksum, valid);
    krb5_k_free_key(context, key);
    return ret;
}