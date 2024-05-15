TIME_t TIME_getTime(void)
{
    static mach_timebase_info_data_t rate;
    static int init = 0;
    if (!init) {
        mach_timebase_info(&rate);
        init = 1;
    }
    {
        TIME_t r;
        r.t = mach_absolute_time() * (Duration_ns)rate.numer
                / (Duration_ns)rate.denom;
        return r;
    }
}