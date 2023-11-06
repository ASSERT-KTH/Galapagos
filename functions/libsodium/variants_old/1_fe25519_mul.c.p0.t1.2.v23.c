fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f0 = f[0], f1 = f[1], f2 = f[2], f3 = f[3], f4 = f[4], f5 = f[5], 
            f6 = f[6], f7 = f[7], f8 = f[8], f9 = f[9];
    int32_t g0 = g[0], g1 = g[1], g2 = g[2], g3 = g[3], g4 = g[4], g5 = g[5], 
            g6 = g[6], g7 = g[7], g8 = g[8], g9 = g[9];

    int32_t f1_2 = 2 * f1, f3_2 = 2 * f3, f5_2 = 2 * f5, f7_2 = 2 * f7, f9_2 = 2 * f9;

    int32_t gsg[] = {19*g1, 19*g2, 19*g3, 19*g4, 19*g5, 19*g6, 19*g7, 19*g8, 19*g9};

    int64_t f0gsg[] = {f0*g0, f0*g1, f0*g2, f0*g3, f0*g4, f0*g5, f0*g6, f0*g7, f0*g8, f0*g9};
    int64_t f1gsg[] = {f1*g0, f1_2*g1, f1*g2, f1_2*g3, f1*g4, f1_2*g5, f1*g6, f1_2*g7,
                      f1*g8, f1_2*g9_19};
    int64_t f2gsg[] = {f2*g0, f2*g1, f2*g2, f2*g3, f2*g4, f2*g5, f2*g6, f2*g7,
                     f2*g8_19, f2*g9_19};
    int64_t f3gsg[] = {f3*g0, f3_2*g1, f3*g2, f3_2*g3, f3*g4, f3_2*g5, f3*g6, 
                      f3_2*g7_19, f3*g8_19, f3_2*g9_19};
    int64_t f4gsg[] = {f4*g0, f4*gsg[0], f4*gsg[1], f4*gsg[2], f4*gsg[3], f4*gsg[4], 
                      f4*gsg[5], f4*gsg[6], f4*gsg[7], f4*gsg[8]};
    int64_t f5gsg[] = {f5_2*g0, f5_2*g1, f5_2*g2, f5_2*g3, f5_2*g4, f5_2*g5_19, 
                       f5_2*g6_19, f5_2*g7_19, f5_2*g8_19, f5_2*g9_19};
    int64_t f6gsg[] = {f6*g0, f6*g1, f6*g2, f6*g3, f6*gsg[3], f6*gsg[4], f6*gsg[5], f6*gsg[6], f6*gsg[7], f6*gsg[8]};
    int64_t f7gsg[] = {f7*g0, f7_2*g1, f7*g2, f7_2*g3_19, f7*g4_19, f7_2*g5_19, f7*g6_19,
                     f7_2*g7_19, f7*g8_19, f7_2*g9_19};
    int64_t f8gsg[] = {f8*g0, f8*g1, f8*gsg[1], f8*gsg[2], f8*gsg[3], f8*gsg[4], 
                      f8*gsg[5], f8*gsg[6], f8*gsg[7], f8*gsg[8]};
    int64_t f9gsg[] = {f9_2*g0, f9_2*g1_19, f9_2*g2_19, f9_2*g3_19, f9_2*g4_19, 
                      f9_2*g5_19, f9_2*g6_19, f9_2*g7_19, f9_2*g8_19, f9_2*g9_19};

    int64_t hsg[] = {  // Sum elements from each f*g[] array respectively
        f0gsg[0] + f1gsg[9] + f2gsg[8] + f3gsg[7] + f4gsg[6] + f5gsg[5] + f6gsg[4] + f7gsg[3] + f8gsg[2] + f9gsg[1],
        f0gsg[1] + f1gsg[0] + f2gsg[9] + f3gsg[8] + f4gsg[7] + f5gsg[6] + f6gsg[5] + f7gsg[4] + f8gsg[3] + f9gsg[2],
        f0gsg[2] + f1gsg[1] + f2gsg[0] + f3gsg[9] + f4gsg[8] + f5gsg[7] + f6gsg[6] + f7gsg[5] + f8gsg[4] + f9gsg[3],
        f0gsg[3] + f1gsg[2] + f2gsg[1] + f3gsg[0] + f4gsg[9] + f5gsg[8] + f6gsg[7] + f7gsg[6] + f8gsg[5] + f9gsg[4],
        f0gsg[4] + f1gsg[3] + f2gsg[2] + f3gsg[1] + f4gsg[0] + f5gsg[9] + f6gsg[8] + f7gsg[7] + f8gsg[6] + f9gsg[5],
        f0gsg[5] + f1gsg[4] + f2gsg[3] + f3gsg[2] + f4gsg[1] + f5gsg[0] + f6gsg[9] + f7gsg[8] + f8gsg[7] + f9gsg[6],
        f0gsg[6] + f1gsg[5] + f2gsg[4] + f3gsg[3] + f4gsg[2] + f5gsg[1] + f6gsg[0] + f7gsg[9] + f8gsg[8] + f9gsg[7],
        f0gsg[7] + f1gsg[6] + f2gsg[5] + f3gsg[4] + f4gsg[2] + f5gsg[2] + f6gsg[1] + f7gsg[0] + f8gsg[9] + f9gsg[8],
        f0gsg[8] + f1gsg[7] + f2gsg[6] + f3gsg[5] + f4gsg[4] + f5gsg[3] + f6gsg[2] + f7gsg[1] + f8gsg[0] + f9gsg[9],
        f0gsg[9] + f1gsg[8] + f2gsg[7] + f3gsg[6] + f4gsg[5] + f5gsg[4] + f6gsg[3] + f7gsg[2] + f8gsg[1] + f9gsg[0]
    };

    for (int i =0; i < 10; i++) {  // Get and subtract carry values one by one
        hsg[(i+1)%10] += (hsg[i] + (int64_t)(1L << (25 + i%2))) >> (26 - i%2);
        hsg[i] -= (hsg[i] + (int64_t)(1L << (25 + i%2))) >> (26 - i%2) * ((int64_t) 1L << (26 - i%2));
    }

    for (int i =0; i < 10; i++) {  // Convert each int64 in hsg array to int32 and assign to h array
        h[i] = (int32_t) hsg[i];
    }
}