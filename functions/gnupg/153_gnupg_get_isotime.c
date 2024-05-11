gnupg_get_isotime (gnupg_isotime_t timebuf)
{
  time_t atime = gnupg_get_time ();
  struct tm *tp;
  struct tm tmbuf;

  tp = gnupg_gmtime (&atime, &tmbuf);
  if (!tp)
    *timebuf = 0;
  else
    snprintf (timebuf, 16, "%04d%02d%02dT%02d%02d%02d",
              1900 + tp->tm_year, tp->tm_mon+1, tp->tm_mday,
              tp->tm_hour, tp->tm_min, tp->tm_sec);
}