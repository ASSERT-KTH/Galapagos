krb5_db_put_principal(krb5_context kcontext, krb5_db_entry *entry)
{
    krb5_error_code status = 0;
    kdb_incr_update_t *upd = NULL;
    char *princ_name = NULL;

    if (logging(kcontext)) {
        upd = k5alloc(sizeof(*upd), &status);
        if (upd == NULL)
            goto cleanup;
        if ((status = ulog_conv_2logentry(kcontext, entry, upd)))
            goto cleanup;

        status = krb5_unparse_name(kcontext, entry->princ, &princ_name);
        if (status != 0)
            goto cleanup;

        upd->kdb_princ_name.utf8str_t_val = princ_name;
        upd->kdb_princ_name.utf8str_t_len = strlen(princ_name);
    }

    status = krb5int_put_principal_no_log(kcontext, entry);
    if (status)
        goto cleanup;

    if (logging(kcontext))
        status = ulog_add_update(kcontext, upd);

cleanup:
    ulog_free_entries(upd, 1);
    return status;
}