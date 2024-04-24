krb5_free_data(krb5_context context, krb5_data *val)
{
    if (val == NULL)
        return;
    free(val->data);
    free(val);
}