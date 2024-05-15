TIME_t TIME_getTime(void)
{
    static LARGE_INTEGER ticksPerSecond;
    static int init = 0;
    if (!init) {
        if (!QueryPerformanceFrequency(&ticksPerSecond)) {
            perror("timefn::QueryPerformanceFrequency");
            abort();
        }
        init = 1;
    }
    {
        TIME_t r;
        LARGE_INTEGER x;
        QueryPerformanceCounter(&x);
        r.t = (Duration_ns)(x.QuadPart * 1000000000ULL / ticksPerSecond.QuadPart);
        return r;
    }
}