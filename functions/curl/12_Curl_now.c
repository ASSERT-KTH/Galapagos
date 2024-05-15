struct curltime Curl_now(void)
{
  /*
  ** Monotonic timer on Mac OS is provided by mach_absolute_time(), which
  ** returns time in Mach "absolute time units," which are platform-dependent.
  ** To convert to nanoseconds, one must use conversion factors specified by
  ** mach_timebase_info().
  */
  static mach_timebase_info_data_t timebase;
  struct curltime cnow;
  uint64_t usecs;

  if(0 == timebase.denom)
    (void) mach_timebase_info(&timebase);

  usecs = mach_absolute_time();
  usecs *= timebase.numer;
  usecs /= timebase.denom;
  usecs /= 1000;

  cnow.tv_sec = usecs / 1000000;
  cnow.tv_usec = (int)(usecs % 1000000);

  return cnow;
}