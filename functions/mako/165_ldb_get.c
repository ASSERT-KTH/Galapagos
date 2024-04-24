ldb_get(ldb_t *db, const ldb_slice_t *key,
                   ldb_slice_t *value,
                   const ldb_readopt_t *options) {
  leveldb_readoptions_t *opt = db->read_options;
  int rc = LDB_OK;
  char *err = NULL;
  char *vp = NULL;
  size_t vn = 0;

  if (options != NULL)
    opt = convert_readopt(options);

  vp = leveldb_get(db->level, opt, key->data, key->size, &vn, &err);

  if (err != NULL) {
    rc = handle_error(err);
    goto done;
  }

  if (vp == NULL)
    rc = LDB_NOTFOUND;

  value->data = (void *)vp;
  value->size = vn;
  value->dummy = 0;

done:
  if (options != NULL)
    leveldb_readoptions_destroy(opt);

  return rc;
}