krb5_dbe_decrypt_key_data(krb5_context kcontext, const krb5_keyblock *mkey,
                          const krb5_key_data *key_data, krb5_keyblock *dbkey,
                          krb5_keysalt *keysalt)
{
    krb5_error_code status = 0;
    kdb_vftabl *v;
    krb5_keyblock *cur_mkey;

    status = get_vftabl(kcontext, &v);
    if (status)
        return status;
    if (mkey || kcontext->dal_handle->master_keylist == NULL)
        return v->decrypt_key_data(kcontext, mkey, key_data, dbkey, keysalt);
    status = decrypt_iterator(kcontext, key_data, dbkey, keysalt);
    if (status == 0)
        return 0;
    if (kcontext->dal_handle->master_keylist) {
        /* Try reloading master keys. */
        cur_mkey = &kcontext->dal_handle->master_keylist->keyblock;
        if (krb5_db_fetch_mkey_list(kcontext,
                                    kcontext->dal_handle->master_princ,
                                    cur_mkey) == 0)
            return decrypt_iterator(kcontext, key_data, dbkey, keysalt);
    }
    return status;
}