krb5_free_creds(krb5_context context, krb5_creds *val)
{
    if (val == NULL)
        return;
    krb5_free_cred_contents(context, val);
    free(val);
}