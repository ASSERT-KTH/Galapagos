ldb_iter_status(const ldb_iter_t *iter) {
  char *err = NULL;

  leveldb_iter_get_error(iter->rep, &err);

  return handle_error(err);
}