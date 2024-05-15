krb5_free_checksum_contents(krb5_context context, krb5_checksum *val)
{
    if (val == NULL)
        return;
    free(val->contents);
    val->contents = NULL;
    val->length = 0;
}