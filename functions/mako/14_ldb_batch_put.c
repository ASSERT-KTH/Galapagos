ldb_batch_put(ldb_batch_t *batch,
              const ldb_slice_t *key,
              const ldb_slice_t *value) {
  ldb_batch_set_count(batch, ldb_batch_count(batch) + 1);
  ldb_buffer_push(&batch->rep, LDB_TYPE_VALUE);
  ldb_slice_export(&batch->rep, key);
  ldb_slice_export(&batch->rep, value);
}