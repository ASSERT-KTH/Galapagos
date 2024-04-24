ldb_open(const char *dbname, const ldb_dbopt_t *options, ldb_t **dbptr) {
  ldb_t *db = safe_malloc(sizeof(ldb_t));
  char *err = NULL;
  int rc;

  if (options == NULL)
    options = ldb_dbopt_default;

  db->dbopt = *options;
  db->ucmp = options->comparator != NULL ? *options->comparator
                                         : bytewise_comparator;
  db->dbopt.comparator = &db->ucmp;
  db->cmp = convert_comparator(&db->ucmp);
  db->policy = NULL;
  db->options = convert_dbopt(options, db->cmp, &db->policy);
  db->read_options = convert_readopt(ldb_readopt_default);
  db->write_options = convert_writeopt(ldb_writeopt_default);
  db->iter_options = convert_readopt(ldb_iteropt_default);
  db->level = leveldb_open(db->options, dbname, &err);

  rc = handle_error(err);

  if (rc == LDB_OK) {
    *dbptr = db;
  } else {
    ldb_close(db);
    *dbptr = NULL;
  }

  return rc;
}