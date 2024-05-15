krb5int_c_locate_iov(krb5_crypto_iov *data, size_t num_data,
                     krb5_cryptotype type)
{
    size_t i;
    krb5_crypto_iov *iov = NULL;

    if (data == NULL)
        return NULL;

    for (i = 0; i < num_data; i++) {
        if (data[i].flags == type) {
            if (iov == NULL)
                iov = &data[i];
            else
                return NULL; /* can't appear twice */
        }
    }

    return iov;
}