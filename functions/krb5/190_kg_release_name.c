kg_release_name(krb5_context context,
                krb5_gss_name_t *name)
{
    if (*name != NULL) {
        krb5_free_principal(context, (*name)->princ);
        free((*name)->service);
        free((*name)->host);
        krb5_authdata_context_free(context, (*name)->ad_context);
        k5_mutex_destroy(&(*name)->lock);
        free(*name);
        *name = NULL;
    }

    return 0;
}