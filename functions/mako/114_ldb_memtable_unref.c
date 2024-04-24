ldb_memtable_unref(ldb_memtable_t *mt) {
  --mt->refs;

  assert(mt->refs >= 0);

  if (mt->refs <= 0)
    ldb_memtable_destroy(mt);
}