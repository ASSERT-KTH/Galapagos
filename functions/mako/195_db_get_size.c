db_get_size(ldb_t *db, const ldb_slice_t *key, ldb_slice_t *val, size_t size) {
  if (!db_get(db, key, val))
    return 0;

  if (val->size == size)
    return 1;

  ldb_free(val->data);

  return db_abort("db_get_size", LDB_CORRUPTION);
}