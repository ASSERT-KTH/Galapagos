static inline void interleave(vec128 *in, int idx0, int idx1, vec128 *mask, int b) {
    int s = 1 << b;

    vec128 x, y;

    x = vec128_or(vec128_and(in[idx0], mask[0]),
                  vec128_sll_2x(vec128_and(in[idx1], mask[0]), s));

    y = vec128_or(vec128_srl_2x(vec128_and(in[idx0], mask[1]), s),
                  vec128_and(in[idx1], mask[1]));

    in[idx0] = x;
    in[idx1] = y;
}