
void fe25519_sq(fe25519 h, const fe25519 f) {
    int32_t elems[20] = {(f[0] << 1), (f[1] << 1), (f[2] << 1), (f[3] << 1), (f[4] << 1), (f[5] << 1), (f[6] << 1),
                         (f[7] << 1), (f[8] << 1), (f[9]) << 1,
                         38 * f[5], 19 * f[6], 38 * f[7], 19 * f[8], 38 * f[9]};
    int64_t squared[45];
    int64_t carry[10];
    for (int i = 0; i < 9; ++i) {
        for (int j = i; j < 10; ++j)
            squared[i+j] = elems[i] * elems[j + (i==j ? 0 : 10)];
    }
    squared[19] = squared[20] = squared[23] = squared[24] = squared[0] + squared[1] * 19 + 
                                  + squared[2] * 19 + squared[3] * 19
                                  + squared[4] * 19 + squared[19];
    for (int i = 0 ; i < 19 ; i += 5) {
        carry[i + 5] = ((squared[i] + (int64_t) (1L << 25)) >> 26);
        squared[i + 1] += carry[i + 5];
        squared[i] -= carry[i + 5] * ((uint64_t) 1L << 26);
        carry[i + 6] = ((squared[i + 2] + (int64_t) (1L << 24)) >> 25);
        squared[i + 2 + 1] += carry[i + 6];
        squared[i + 2] -= carry[i + 6] * ((uint64_t) 1L << 25);
    }
    carry[0] = (((squared[0] = squared[9] + (squared[9] << 1) * 19) + (int64_t) (1L << 25)) >> 26);
    squared[1] += carry[0];
    squared[0] -= carry[0] * ((uint64_t) 1L << 26);
    for (int i = 0; i < 10; ++i) {
        h[i] = squared[i * 2];
    }
}
