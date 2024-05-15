krb5_c_decrypt(krb5_context context, const krb5_keyblock *keyblock,
               krb5_keyusage usage, const krb5_data *cipher_state,
               const krb5_enc_data *input, krb5_data *output)
{
    krb5_key key;
    krb5_error_code ret;

    ret = krb5_k_create_key(context, keyblock, &key);
    if (ret != 0)
        return ret;
    ret = krb5_k_decrypt(context, key, usage, cipher_state, input, output);
    krb5_k_free_key(context, key);
    return ret;
}