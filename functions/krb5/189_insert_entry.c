insert_entry(krb5_context context, k5_memrcache mrc, const krb5_data *tag,
             krb5_timestamp now)
{
    krb5_error_code ret;
    struct entry *entry = NULL;

    entry = calloc(1, sizeof(*entry));
    if (entry == NULL)
        return ENOMEM;
    entry->timestamp = now;

    ret = krb5int_copy_data_contents(context, tag, &entry->tag);
    if (ret)
        goto error;

    ret = k5_hashtab_add(mrc->hash_table, entry->tag.data, entry->tag.length,
                         entry);
    if (ret)
        goto error;
    K5_TAILQ_INSERT_TAIL(&mrc->expiration_queue, entry, links);

    return 0;

error:
    if (entry != NULL) {
        krb5_free_data_contents(context, &entry->tag);
        free(entry);
    }
    return ret;
}