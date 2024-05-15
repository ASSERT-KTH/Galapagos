TIME_t TIME_getTime(void)
{
    /* time must be initialized, othersize it may fail msan test.
     * No good reason, likely a limitation of timespec_get() for some target */
    struct timespec time = { 0, 0 };
    if (clock_gettime(CLOCK_MONOTONIC, &time) != 0) {
        perror("timefn::clock_gettime(CLOCK_MONOTONIC)");
        abort();
    }
    {   TIME_t r;
        r.t = (Duration_ns)time.tv_sec * 1000000000ULL
                + (Duration_ns)time.tv_nsec;
        return r;
    }
}