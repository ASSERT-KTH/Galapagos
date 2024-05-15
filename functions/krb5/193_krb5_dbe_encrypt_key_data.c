krb5_dbe_encrypt_key_data(krb5_context kcontext, const krb5_keyblock *mkey,
                          const krb5_keyblock *dbkey,
                          const krb5_keysalt *keysalt, int keyver,
                          krb5_key_data *key_data)
{
    krb5_error_code status = 0;
    kdb_vftabl *v;

    status = get_vftabl(kcontext, &v);
    if (status)
        return status;
    return v->encrypt_key_data(kcontext, mkey, dbkey, keysalt, keyver,
                               key_data);
}