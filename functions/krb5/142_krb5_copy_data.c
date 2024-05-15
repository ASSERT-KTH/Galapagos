krb5_copy_data(krb5_context context, const krb5_data *indata, krb5_data **outdata)
{
    krb5_data *tempdata;
    krb5_error_code retval;

    if (!indata) {
        *outdata = 0;
        return 0;
    }

    if (!(tempdata = (krb5_data *)malloc(sizeof(*tempdata))))
        return ENOMEM;

    retval = krb5int_copy_data_contents(context, indata, tempdata);
    if (retval) {
        free(tempdata);
        return retval;
    }

    *outdata = tempdata;
    return 0;
}