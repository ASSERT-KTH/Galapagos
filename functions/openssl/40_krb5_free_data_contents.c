krb5_free_data_contents(krb5_context context, krb5_data *val)
{
    if (val == NULL)
        return;
    free(val->data);
    val->data = NULL;
    val->length = 0;
}