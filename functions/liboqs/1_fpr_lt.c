static inline int fpr_lt(uint64_t x, uint64_t y) {
    /*
     * If both x and y are positive, then a signed comparison yields
     * the proper result:
     *   - For positive values, the order is preserved.
     *   - The sign bit is at the same place as in integers, so
     *     sign is preserved.
     * Moreover, we can compute [x < y] as sgn(x-y) and the computation
     * of x-y will not overflow.
     *
     * If the signs differ, then sgn(x) gives the proper result.
     *
     * If both x and y are negative, then the order is reversed.
     * Hence [x < y] = sgn(y-x). We must compute this separately from
     * sgn(x-y); simply inverting sgn(x-y) would not handle the edge
     * case x = y properly.
     */
    int cc0, cc1;
    int64_t sx;
    int64_t sy;

    sx = *(int64_t *)&x;
    sy = *(int64_t *)&y;
    sy &= ~((sx ^ sy) >> 63); /* set sy=0 if signs differ */

    cc0 = (int)((sx - sy) >> 63) & 1; /* Neither subtraction overflows when */
    cc1 = (int)((sy - sx) >> 63) & 1; /* the signs are the same. */

    return cc0 ^ ((cc0 ^ cc1) & (int)((x & y) >> 63));
}
