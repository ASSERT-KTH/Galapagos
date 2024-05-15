krb5_free_pa_data(krb5_context context, krb5_pa_data **val)
{
    krb5_pa_data **temp;

    if (val == NULL)
        return;
    for (temp = val; *temp; temp++) {
        free((*temp)->contents);
        free(*temp);
    }
    free(val);
}