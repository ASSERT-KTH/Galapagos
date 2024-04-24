db_get(ldb_t *db, const ldb_slice_t *key, ldb_slice_t *val) {
  int rc = ldb_get(db, key, val, 0);

  if (rc == LDB_OK)
    return 1;

  if (rc == LDB_NOTFOUND)
    return 0;

  return db_abort("db_get", rc);
}