svGetValueStr(shvarFile *s, const char *key, char **to_free)
{
    const char *value;

    g_return_val_if_fail(s, NULL);
    g_return_val_if_fail(key, NULL);
    g_return_val_if_fail(to_free, NULL);

    value = _svGetValue(s, key, to_free);
    if (!value || !value[0]) {
        nm_assert(!*to_free);
        return NULL;
    }
    return value;
}