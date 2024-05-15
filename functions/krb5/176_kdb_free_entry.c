kdb_free_entry(kadm5_server_handle_t handle,
               krb5_db_entry *kdb, osa_princ_ent_rec *adb)
{
    XDR xdrs;


    if (kdb)
        krb5_db_free_principal(handle->context, kdb);

    if (adb) {
        xdrmem_create(&xdrs, NULL, 0, XDR_FREE);
        xdr_osa_princ_ent_rec(&xdrs, adb);
        xdr_destroy(&xdrs);
    }

    return(0);
}