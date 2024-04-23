parse_datetime (struct timespec *result, char const *p,
                struct timespec const *now)
{
  char const *tzstring = getenv ("TZ");
  timezone_t tz = tzalloc (tzstring);
  if (!tz)
    return false;
  bool ok = parse_datetime_body (result, p, now, 0, tz, tzstring);
  tzfree (tz);
  return ok;
}