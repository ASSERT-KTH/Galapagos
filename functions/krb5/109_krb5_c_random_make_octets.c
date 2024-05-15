krb5_c_random_make_octets(krb5_context context, krb5_data *outdata)
{
    krb5_boolean res;

    res = get_os_entropy((uint8_t *)outdata->data, outdata->length);
    return res ? 0 : KRB5_CRYPTO_INTERNAL;
}