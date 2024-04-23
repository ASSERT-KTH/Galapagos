ldb_log(ldb_logger_t *logger, const char *fmt, ...) {
  va_list ap;

  va_start(ap, fmt);

  if (logger != NULL && logger->logv != NULL)
    logger->logv(logger->state, fmt, ap);

  va_end(ap);
}