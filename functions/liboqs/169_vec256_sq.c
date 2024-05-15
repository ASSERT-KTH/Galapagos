void vec256_sq(vec256 *out, vec256 *in) {
    int i;
    vec256 result[GFBITS], t;

    t = vec256_xor(in[11], in[12]);

    result[0] = vec256_xor(in[0], in[11]);
    result[1] = vec256_xor(in[7], t);
    result[2] = vec256_xor(in[1], in[7]);
    result[3] = vec256_xor(in[8], t);
    result[4] = vec256_xor(in[2], in[7]);
    result[4] = vec256_xor(result[4], in[8]);
    result[4] = vec256_xor(result[4], t);
    result[5] = vec256_xor(in[7], in[9]);
    result[6] = vec256_xor(in[3], in[8]);
    result[6] = vec256_xor(result[6], in[9]);
    result[6] = vec256_xor(result[6], in[12]);
    result[7] = vec256_xor(in[8], in[10]);
    result[8] = vec256_xor(in[4], in[9]);
    result[8] = vec256_xor(result[8], in[10]);
    result[9] = vec256_xor(in[9], in[11]);
    result[10] = vec256_xor(in[5], in[10]);
    result[10] = vec256_xor(result[10], in[11]);
    result[11] = vec256_xor(in[10], in[12]);
    result[12] = vec256_xor(in[6], t);

    for (i = 0; i < GFBITS; i++) {
        out[i] = result[i];
    }
}