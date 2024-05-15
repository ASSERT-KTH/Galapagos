krb5_free_authdata(krb5_context context, krb5_authdata **val)
{
    krb5_authdata **temp;

    if (val == NULL)
        return;
    for (temp = val; *temp; temp++) {
        free((*temp)->contents);
        free(*temp);
    }
    free(val);
}