fe25519_mul_ALT(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t fvals[10], gvals[10], c_vals[10];
    int64_t f_g[100], h_vals[10];
    for (int i = 0; i < 10; i++) {
        fvals[i] = f[i];
        gvals[i] = g[i];
    }

    for (int i = 1; i < 10; i += 2)
        gvals[i] *= 19;

    for (int i = 1; i < 10; i += 2)
        fvals[i] *= 2;
 
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            f_g[10 * i + j] = (int64_t)fvals[i] * gvals[j];
 
    for (int i = 1; i < 10; i += 2)
        for (int j = 10 - i; j < 10; j++)
            f_g[10 * (i - 1) + (j + i - 2)] += f_g[10 * i + j - i];

    for (int i = 0; i < 10; i++)
        h_vals[i] = f_g[i * 10];

    for (long i = 9; i --> 0;)
    {
        c_vals[i] = (h_vals[i + 1] + (int64_t)(1L << (24 + (i & 1)))) >> (i & 1 ? 25 : 26);
        h_vals[i] += c_vals[i];
    }

    h_vals[0] += h_vals[9] / (1L << 25) * 19;
    h_vals[9] &= (1L << 25) - 1;
  
    c_vals[0] = (h_vals[0] + (int64_t)(1 << 25)) >> 26;
    h_vals[0] &= (1L << 26) - 1;
    h_vals[1] = h_vals[0] + c_vals[0];

    for (int i = 0; i < 10; i++) {
        h[i] = (int32_t) h_vals[i];
    }
}