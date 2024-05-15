krb5_c_encrypt_length(krb5_context context, krb5_enctype enctype,
                      size_t inputlen, size_t *length)
{
    const struct krb5_keytypes *ktp;
    unsigned int header_len = 0, padding_len = 0, trailer_len = 0;

    ktp = find_enctype(enctype);
    if (ktp == NULL)
        return KRB5_BAD_ENCTYPE;

    header_len = ktp->crypto_length(ktp, KRB5_CRYPTO_TYPE_HEADER);
    padding_len = krb5int_c_padding_length(ktp, inputlen);
    trailer_len = ktp->crypto_length(ktp, KRB5_CRYPTO_TYPE_TRAILER);

    *length = header_len + inputlen + padding_len + trailer_len;
    return 0;
}