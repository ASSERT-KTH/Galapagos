isotime2epoch (const char *string)
{
  struct tm tmbuf;

  if (isotime_make_tm (string, &tmbuf))
    return (time_t)(-1);

  return timegm (&tmbuf);
}