static inline void k5_mutex_unlock(k5_mutex_t *m)
{
    int r = k5_os_mutex_unlock(m);
#ifndef NDEBUG
    if (r != 0) {
        fprintf(stderr, "k5_mutex_unlock: Received error %d (%s)\n",
                r, strerror(r));
    }
#endif
    assert(r == 0);
}