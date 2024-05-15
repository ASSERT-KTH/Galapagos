int qcow2_cache_put(BlockDriverState *bs, Qcow2Cache *c, void **table)
{
    int i;

    for (i = 0; i < c->size; i++) {
        if (c->entries[i].table == *table) {
            goto found;
        }
    }
    return -ENOENT;

found:
    c->entries[i].ref--;
    *table = NULL;

    assert(c->entries[i].ref >= 0);
    return 0;
}