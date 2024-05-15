int TIME_support_MT_measurements(void)
{
#if defined(TIME_MT_MEASUREMENTS_NOT_SUPPORTED)
    return 0;
#else
    return 1;
#endif
}