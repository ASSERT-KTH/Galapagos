AVDictionaryEntry *av_dict_get(const AVDictionary *m, const char *key,
                               const AVDictionaryEntry *prev, int flags)
{
    const AVDictionaryEntry *entry = prev;
    unsigned int j;

    if (!key)
        return NULL;

    while ((entry = av_dict_iterate(m, entry))) {
        const char *s = entry->key;
        if (flags & AV_DICT_MATCH_CASE)
            for (j = 0; s[j] == key[j] && key[j]; j++)
                ;
        else
            for (j = 0; av_toupper(s[j]) == av_toupper(key[j]) && key[j]; j++)
                ;
        if (key[j])
            continue;
        if (s[j] && !(flags & AV_DICT_IGNORE_SUFFIX))
            continue;
        return (AVDictionaryEntry *)entry;
    }
    return NULL;
}