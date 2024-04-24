report_corruption(ldb_reporter_t *reporter, size_t bytes, int status) {
  /* We print error messages for corruption, but continue repairing. */
  ldb_log(reporter->info_log, "Log #%lu: dropping %d bytes; %s",
                              (unsigned long)reporter->lognum,
                              (signed int)bytes,
                              ldb_strerror(status));
}