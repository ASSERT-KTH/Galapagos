nm_utils_get_monotonic_timestamp_msec(void)
{
    const GlobalState *p;
    struct timespec    tp;

    p = _t_clock_gettime(&tp);

    /* Although the result will always be positive, we return a signed
     * integer, which makes it easier to calculate time differences (when
     * you want to subtract signed values).
     **/
    return (((gint64) tp.tv_sec) + p->offset_sec) * ((gint64) 1000)
           + (tp.tv_nsec / (NM_UTILS_NSEC_PER_SEC / 1000));
}