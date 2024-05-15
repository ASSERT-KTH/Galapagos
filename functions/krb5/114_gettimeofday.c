gettimeofday(struct timeval *tv, void *ignore_tz)
{
    struct _timeb tb;
    _tzset();
    _ftime(&tb);
    if (tv) {
        tv->tv_sec = tb.time;
        tv->tv_usec = tb.millitm * 1000;
    }
    return 0;
}