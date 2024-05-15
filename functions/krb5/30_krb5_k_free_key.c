krb5_k_free_key(krb5_context context, krb5_key key)
{
    struct derived_key *dk;
    const struct krb5_keytypes *ktp;

    if (key == NULL || --key->refcount > 0)
        return;

    /* Free the derived key cache. */
    while ((dk = key->derived) != NULL) {
        key->derived = dk->next;
        free(dk->constant.data);
        krb5_k_free_key(context, dk->dkey);
        free(dk);
    }
    krb5int_c_free_keyblock_contents(context, &key->keyblock);
    if (key->cache) {
        ktp = find_enctype(key->keyblock.enctype);
        if (ktp && ktp->enc->key_cleanup)
            ktp->enc->key_cleanup(key);
    }
    free(key);
}