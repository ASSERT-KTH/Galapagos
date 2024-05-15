alloc_data(krb5_data *data, unsigned int len)
{
    /* Allocate at least one byte since zero-byte allocs may return NULL. */
    char *ptr = (char *) calloc((len > 0) ? len : 1, 1);

    if (ptr == NULL)
        return ENOMEM;
    data->magic = KV5M_DATA;
    data->data = ptr;
    data->length = len;
    return 0;
}