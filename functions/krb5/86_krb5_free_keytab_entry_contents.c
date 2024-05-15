krb5_free_keytab_entry_contents (krb5_context context, krb5_keytab_entry *entry)
{
    if (!entry)
        return 0;

    krb5_free_principal(context, entry->principal);
    if (entry->key.contents) {
        zap((char *)entry->key.contents, entry->key.length);
        free(entry->key.contents);
    }
    return 0;
}