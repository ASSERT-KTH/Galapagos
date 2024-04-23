krb5_free_principal(krb5_context context, krb5_principal val)
{
    krb5_int32 i;

    if (!val)
        return;

    if (val->data) {
        i = val->length;
        while(--i >= 0)
            free(val->data[i].data);
        free(val->data);
    }
    free(val->realm.data);
    free(val);
}