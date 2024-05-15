static void LZ4IO_finalTimeDisplay(TIME_t timeStart, clock_t cpuStart, unsigned long long size)
{
#if LZ4IO_MULTITHREAD
    if (!TIME_support_MT_measurements()) {
        DISPLAYLEVEL(5, "time measurements not compatible with multithreading \n");
    } else
#endif
    {
        Duration_ns duration_ns = TIME_clockSpan_ns(timeStart);
        double const seconds = (double)(duration_ns + !duration_ns) / (double)1000000000.;
        double const cpuLoad_s = (double)(clock() - cpuStart) / CLOCKS_PER_SEC;
        DISPLAYLEVEL(3,"Done in %.2f s ==> %.2f MiB/s  (cpu load : %.0f%%)\n", seconds,
                        size / seconds / 1024 / 1024,
                        (cpuLoad_s / seconds) * 100.);
    }
}