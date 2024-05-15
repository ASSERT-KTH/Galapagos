k5_hashtab_get(struct k5_hashtab *ht, const void *key, size_t klen)
{
    size_t i;
    struct entry *ent;

    i = siphash24(key, klen, ht->k0, ht->k1) % ht->nbuckets;
    K5_SLIST_FOREACH(ent, &ht->buckets[i], next) {
        if (ent->klen == klen && memcmp(ent->key, key, klen) == 0)
            return ent->val;
    }
    return NULL;
}