static inline int
fpr_lt(int64_t x, int64_t y) {
    int cc0, cc1;
    int64_t sx;
    int64_t sy;

    sx = *(int64_t *)&x;
    sy = *(int64_t *)&y;
    sy &= ~((sx ^ sy) >> 63); 

    cc0 = (int)((sx - sy) >> 63) & 1;
    cc1 = (int)((sy - sx) >> 63) & 1;

    return cc0 ^ ((cc0 ^ cc1) & (int)((x & y) >> 63));
}
