fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f1 = f[1], f3 = f[3], f5 = f[5], f7 = f[7], f9 = f[9];

    int32_t g0 = g[0];
    int32_t g1 = g[1];
    int32_t g2 = g[2];
    int32_t g3 = g[3];
    int32_t g4 = g[4];
    int32_t g5 = g[5];
    int32_t g6 = g[6];
    int32_t g7 = g[7];
    int32_t g8 = g[8];
    int32_t g9 = g[9];

    int32_t g1_19 = 19 * g1; /* 1.959375*2^29 */
    int32_t g2_19 = 19 * g2; /* 1.959375*2^30; still ok */
    int32_t g3_19 = 19 * g3;
    int32_t g4_19 = 19 * g4;
    int32_t g5_19 = 19 * g5;
    
    int32_t g6_19;
    int32_t g7_19;
    int32_t g8_19;
    int32_t g9_19; 

    g6_19 = 19 * g6;
    g7_19 = 19 * g7;
    g8_19 = 19 * g8;
    g9_19 = 19 * g9;

    int64_t f0g0    = f[0] * (int64_t) g0;
    int64_t f0g1    = f[0] * (int64_t) g1;
    int64_t f0g2    = f[0] * (int64_t) g2;
    int64_t f0g3    = f[0] * (int64_t) g3;
    int64_t f0g4    = f[0] * (int64_t) g4;
    int64_t f0g5    = f[0] * (int64_t) g5;
    int64_t f0g6    = f[0] * (int64_t) g6;
    int64_t f0g7    = f[0] * (int64_t) g7;
    int64_t f0g8    = f[0] * (int64_t) g8;
    int64_t f0g9    = f[0] * (int64_t) g9;

    int64_t f1g0    = f1 * (int64_t) g0;
    int64_t f2g2    = f[2] * (int64_t) g2;
    int64_t f3g4    = f3 * (int64_t) g4;
    
    f1 = 2*f1;
    f3 = 2*f3; 
    f5 = 2*f5;
    f7 = 2*f7;
    f9 = 2*f9;

    int64_t f1g1_2  = (f1 * (int64_t) g1);
    int64_t f1g2    = (f1/2) * (int64_t) g2;
    int64_t f1g3_2  = (f1 * (int64_t) g3);

    h[8] = 0; // Initialize

    constrantHandling(h);     // Taking parts inside this unknown function

    h[9] = (int32_t)(f0g9 + f1g8 + f2g7 + f3g6 + (f3 % 2) * g5 + f5 * (int64_t) g4);

    for(int idx = 0; idx <=8; idx){ // Note idx == 9 controlled in outer space
      if((int64_t)(1L << 24) + carry[h[idx]() >= 25)          // Expanding functionality to guard against carries of interest.
         h[idx+1] += carry(h[idx()])
       else break
    }
  
    h[0] = (int32_t)h[0];

}
