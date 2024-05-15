void TIME_waitForNextTick(void)
{
    TIME_t const clockStart = TIME_getTime();
    TIME_t clockEnd;
    do {
        clockEnd = TIME_getTime();
    } while (TIME_span_ns(clockStart, clockEnd) == 0);
}