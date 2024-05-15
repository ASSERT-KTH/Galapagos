static inline void interleave(vec256 *in, int idx0, int idx1, vec256 *mask, int b) {
    int s = 1 << b;

    vec256 x, y;

    x = vec256_or(vec256_and(in[idx0], mask[0]),
                  vec256_sll_4x(vec256_and(in[idx1], mask[0]), s));

    y = vec256_or(vec256_srl_4x(vec256_and(in[idx0], mask[1]), s),
                  vec256_and(in[idx1], mask[1]));

    in[idx0] = x;
    in[idx1] = y;
}