void warnf(struct GlobalConfig *config, const char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  voutf(config, WARN_PREFIX, fmt, ap);
  va_end(ap);
}