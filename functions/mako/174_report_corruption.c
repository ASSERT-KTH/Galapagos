report_corruption(ldb_reporter_t *report, size_t bytes, int status) {
  ldb_log(report->info_log, "%s%s: dropping %d bytes; %s",
          report->status == NULL ? "(ignoring error) " : "",
          report->fname, (int)bytes, ldb_strerror(status));

  if (report->status != NULL && *report->status == LDB_OK)
    *report->status = status;
}