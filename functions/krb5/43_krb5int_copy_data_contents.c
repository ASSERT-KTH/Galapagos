krb5int_copy_data_contents(krb5_context context, const krb5_data *indata, krb5_data *outdata)
{
    if (!indata) {
        return EINVAL;
    }

    outdata->length = indata->length;
    if (outdata->length) {
        if (!(outdata->data = malloc(outdata->length))) {
            return ENOMEM;
        }
        memcpy(outdata->data, indata->data, outdata->length);
    } else
        outdata->data = 0;
    outdata->magic = KV5M_DATA;

    return 0;
}