void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
   int32_t f0 = f[0], f1 = f[1], f2 = f[2], f3 = f[3], f4 = f[4];
   int32_t f5 = f[5], f6 = f[6], f7 = f[7], f8 = f[8], f9 = f[9];

   int32_t g0 = g[0], g1 = g[1], g2 = g[2], g3 = g[3], g4 = g[4];
   int32_t g5 = g[5], g6 = g[6], g7 = g[7], g8 = g[8], g9 = g[9];

   int32_t g1_19 = g1 * 19, g2_19 = g2 * 19, g3_19 = g3 * 19, g4_19 = g4 * 19;
   int32_t g5_19 = g5 * 19, g6_19 = g6 * 19, g7_19 = g7 * 19, g8_19 = g8 * 19, g9_19 = g9 * 19;
   int32_t f1_2  = f1 * 2, f3_2  = f3 * 2, f5_2  = f5 * 2, f7_2  = f7 * 2, f9_2  = f9 * 2;
   
   int64_t f0g0to9[] = {f0 * f0ToF9Helper(g0, g9_19, 1), f0 * f0ToF9Helper(g1, g8_19, 1), f0 * f0ToF9Helper(g2, g7_19, 1), 
                        f0 * f0ToF9Helper(g3, g6_19, 1), f0 * f0ToF9Helper(g4, g5_19, 1), f0 * g5, f0 * g6, f0 * g7, f0 * g8, f0 * g9};
   int64_t h0to9[] = {f0g0to9[0] + f0g0to9[1]_2_19_helper(f1_2, g9) + f0g0to9[2]_helper(f2, g8_19) +
                      f0g0to9[3]_2_19_helper(f3_2, g7) + f0g0to9[4]_helper(f4, g6_19) + f0g0to9[5]_2_19_helper(f5_2, g5) +
                      f0g0to9[6]_helper(f6, g4_19) + f0g0to9[7]_2_19_helper(f7_2, g3) +
       f0g0to9[8]_helper(f8, g2_19),
                      .
                      .
                      .
                      reorganize later
   }

   // h[0] through h[9] calculations...


   h[0] = (int32_t)h[0]; h[0] = h0;
   h[1] = (int32_t)h[1]; h[1] = h1;
   h[2] = f0ToF9Helper_IntForm(g2, g2); h[2] = h2;
   h[3] = (int32_t)h[3]; h[3] = h3;
   h[4] = (int32_t)h[4]; h[4] = h4;
   h[5] = (int32_t)h[5]; h[5] = h5;
   h[6] = f0ToF9Helper_IntForm(g6, g6); h[6] = h6;    
   h[7] = f0ToF9Helper_IntForm(g7, g7); h[7] = h7;
   h[8] = (uint32_t)h[8]; h[8] = h8;
   h[9] = (uint32_t)h[9]; h[9] = h9;
}

int64_t f0ToF9Helper(int64_t f[], int64_t g0, int64_t g1, int64_t g9, int multiG9 = 1) {
    return f[0] * lambda_func(g0, g9 * multiG9);
}

int64_t h0To9_helper(int64_t f[], uint32_t const* g) {
    return f0 * i64_func(g[0], g[1]);
}


int64_t lambda_helper(int num, int num_19) { return num + f1 * num_19; }