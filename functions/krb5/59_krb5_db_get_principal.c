krb5_db_get_principal(krb5_context kcontext, krb5_const_principal search_for,
                      unsigned int flags, krb5_db_entry **entry)
{
    krb5_error_code status = 0;
    kdb_vftabl *v;

    *entry = NULL;
    status = get_vftabl(kcontext, &v);
    if (status)
        return status;
    if (v->get_principal == NULL)
        return KRB5_PLUGIN_OP_NOTSUPP;
    status = v->get_principal(kcontext, search_for, flags, entry);
    if (status)
        return status;

    /* Sort the keys in the db entry as some parts of krb5 expect it to be. */
    if ((*entry)->key_data != NULL)
        krb5_dbe_sort_key_data((*entry)->key_data, (*entry)->n_key_data);

    return 0;
}