krb5_db_free_principal(krb5_context kcontext, krb5_db_entry *entry)
{
    kdb_vftabl *v;
    int i;

    if (entry == NULL)
        return;
    if (entry->e_data != NULL) {
        if (get_vftabl(kcontext, &v) == 0 && v->free_principal_e_data != NULL)
            v->free_principal_e_data(kcontext, entry->e_data);
        else
            free(entry->e_data);
    }
    krb5_free_principal(kcontext, entry->princ);
    free_tl_data(entry->tl_data);
    for (i = 0; i < entry->n_key_data; i++)
        krb5_dbe_free_key_data_contents(kcontext, &entry->key_data[i]);
    free(entry->key_data);
    free(entry);
}