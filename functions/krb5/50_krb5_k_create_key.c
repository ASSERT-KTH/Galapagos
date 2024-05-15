krb5_k_create_key(krb5_context context, const krb5_keyblock *key_data,
                  krb5_key *out)
{
    krb5_key key = NULL;
    krb5_error_code code;

    *out = NULL;

    key = malloc(sizeof(*key));
    if (key == NULL)
        return ENOMEM;
    code = krb5int_c_copy_keyblock_contents(context, key_data, &key->keyblock);
    if (code)
        goto cleanup;

    key->refcount = 1;
    key->derived = NULL;
    key->cache = NULL;
    *out = key;
    return 0;

cleanup:
    free(key);
    return code;
}