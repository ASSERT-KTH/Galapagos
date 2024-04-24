static inline void k5_mutex_lock(k5_mutex_t *m)
{
    int r = k5_os_mutex_lock(m);
#ifndef NDEBUG
    if (r != 0) {
        fprintf(stderr, "k5_mutex_lock: Received error %d (%s)\n",
                r, strerror(r));
    }
#endif
    assert(r == 0);
}