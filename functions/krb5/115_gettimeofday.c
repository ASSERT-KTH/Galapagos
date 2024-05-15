gettimeofday(
    struct timeval *tv,
    struct timezone *tz
    )
{
    struct _timeb tb;
    _tzset();
    _ftime(&tb);
    if (tv) {
	tv->tv_sec = tb.time;
	tv->tv_usec = tb.millitm * 1000;
    }
    if (tz) {
	tz->tz_minuteswest = tb.timezone;
	tz->tz_dsttime = tb.dstflag;
    }
    return 0;
}