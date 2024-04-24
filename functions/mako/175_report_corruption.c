report_corruption(ldb_reporter_t *report, size_t bytes, int status) {
  ldb_buffer_t r;

  ldb_buffer_init(&r);
  ldb_buffer_string(&r, "corruption: ");
  ldb_buffer_number(&r, bytes);

  ldb_buffer_string(&r, " bytes; ");
  ldb_buffer_string(&r, ldb_strerror(status));
  ldb_buffer_push(&r, '\n');

  stream_append(report->dst, &r);
  ldb_buffer_clear(&r);
}