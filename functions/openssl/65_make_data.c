make_data(void *data, unsigned int len)
{
    krb5_data d;

    d.magic = KV5M_DATA;
    d.data = (char *) data;
    d.length = len;
    return d;
}