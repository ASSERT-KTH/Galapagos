db_write(ldb_t *db, ldb_batch_t *batch) {
  int rc = ldb_write(db, batch, 0);

  ldb_batch_clear(batch);

  if (rc != LDB_OK)
    db_abort("db_write", rc);
}