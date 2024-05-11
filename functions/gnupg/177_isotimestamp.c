isotimestamp (u32 stamp)
{
  static char buffer[25+5];
  struct tm *tp;
  time_t atime = stamp;

  if (IS_INVALID_TIME_T (atime))
    {
      strcpy (buffer, "????" "-??" "-??" " " "??" ":" "??" ":" "??");
    }
  else
    {
      tp = gmtime ( &atime );
      snprintf (buffer, sizeof buffer, "%04d-%02d-%02d %02d:%02d:%02d",
                1900+tp->tm_year, tp->tm_mon+1, tp->tm_mday,
                tp->tm_hour, tp->tm_min, tp->tm_sec);
    }
  return buffer;
}