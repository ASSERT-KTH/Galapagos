ldb_iterator(ldb_t *db, const ldb_readopt_t *options) {
  ldb_iter_t *iter = safe_malloc(sizeof(ldb_iter_t));
  leveldb_readoptions_t *opt = db->iter_options;

  if (options != NULL) {
    opt = convert_readopt(options);
    iter->options = opt;
  } else {
    iter->options = NULL;
  }

  iter->rep = leveldb_create_iterator(db->level, opt);
  iter->ucmp = &db->ucmp;

  return iter;
}