TIME_t TIME_getTime(void)
{
    /* time must be initialized, othersize it may fail msan test */
    struct timespec time = { 0, 0 };
    if (timespec_get(&time, TIME_UTC) != TIME_UTC) {
        perror("timefn::timespec_get(TIME_UTC)");
        abort();
    }
    {
        TIME_t r;
        r.t = (Duration_ns)time.tv_sec * 1000000000ULL
                + (Duration_ns)time.tv_nsec;
        return r;
    }
}