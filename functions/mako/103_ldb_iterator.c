ldb_iterator(ldb_t *db, const ldb_readopt_t *options) {
  const ldb_comparator_t *ucmp = ldb_user_comparator(db);
  ldb_seqnum_t latest_snapshot;
  ldb_iter_t *iter;
  uint32_t seed;

  if (options == NULL)
    options = ldb_iteropt_default;

  iter = ldb_internal_iterator(db, options, &latest_snapshot, &seed);

  return ldb_dbiter_create(db, ucmp, iter,
                           (options->snapshot != NULL
                              ? options->snapshot->sequence
                              : latest_snapshot),
                           seed);
}