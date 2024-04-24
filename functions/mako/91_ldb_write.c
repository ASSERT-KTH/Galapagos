ldb_write(ldb_t *db, ldb_batch_t *updates, const ldb_writeopt_t *options) {
  leveldb_writeoptions_t *opt = db->write_options;
  char *err = NULL;

  if (options != NULL)
    opt = convert_writeopt(options);

  leveldb_write(db->level, opt, updates->rep, &err);

  if (options != NULL)
    leveldb_writeoptions_destroy(opt);

  return handle_error(err);
}