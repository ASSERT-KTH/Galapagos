void ldb_buffer_clear(ldb_buffer_t *buffer) {
  if (buffer && buffer->alloc > 0) {
    ldb_free(buffer->data);
    buffer->data = NULL;
    buffer->alloc = 0;
    buffer->size = 0;
  }
}