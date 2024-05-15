int LZ4IO_defaultNbWorkers(void)
{
#if LZ4IO_MULTITHREAD
    int const nbCores = UTIL_countCores();
    int const spared = 1 + ((unsigned)nbCores >> 3);
    if (nbCores <= spared) return 1;
    return nbCores - spared;
#else
    return 1;
#endif
}