ldb_iter_destroy(ldb_iter_t *iter) {
  leveldb_iter_destroy(iter->rep);

  if (iter->options != NULL)
    leveldb_readoptions_destroy(iter->options);

  safe_free(iter);
}