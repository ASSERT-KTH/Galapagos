krb5_free_addresses(krb5_context context, krb5_address **val)
{
    krb5_address **temp;

    if (val == NULL)
        return;
    for (temp = val; *temp; temp++) {
        free((*temp)->contents);
        free(*temp);
    }
    free(val);
}