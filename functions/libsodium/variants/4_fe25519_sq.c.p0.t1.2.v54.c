fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t g[10], c[10];
    memcpy(g, f, 10*sizeof(int32_t));

    int32_t g0_2  = 2 * g[0];
    int32_t g1_2  = 2 * g[1];
    int32_t g2_2  = 2 * g[2];
    int32_t g3_2  = 2 * g[3];
    int32_t g4_2  = 2 * g[4];
    int32_t g5_38 = 38 * g[5];
    int32_t g6_19 = 19 * g[6];
    int32_t g7_38 = 38 * g[7];
    int32_t g8_19 = 19 * g[8];
    int32_t g9_38 = 38 * g[9];

    int64_t g0sqr    = g[0] * (int64_t) g[0];
    int64_t g0g1_2  = g0_2 * (int64_t) g[1];
    int64_t g0g2_2  = g0_2 * (int64_t) g[2];
    int64_t g0g3_2  = g0_2 * (int64_t) g[3];
    int64_t g0g4_2  = g0_2 * (int64_t) g[4];
    int64_t g1sqr_2  = g1_2 * (int64_t) g[1];
    int64_t g1g2_2  = g1_2 * (int64_t) g[2];
    int64_t g1g3_4  = g1_2 * (int64_t) g3_2;
    int64_t g1g4_2  = g1_2 * (int64_t) g[4];
    int64_t g2sqr    = g[2] * (int64_t) g[2];
    int64_t g2g3_2  = g2_2 * (int64_t) g[3];
    int64_t g2g4_2  = g2_2 * (int64_t) g[4];

    int64_t gsum = g0sqr + g0g1_2 + g0g2_2 + g0g3_2 + g0g4_2 + g1sqr_2 + g1g2_2 + g1g3_4 + g1g4_2 + g2sqr + g2g3_2 + g2g4_2;

    c[0] = (int32_t) (gsum                  % (1ULL << 26));
    c[1] = (int32_t) ((gsum >> 26 | gsum >> 51)*2 % (1ULL << 25));
    c[2] = (int32_t) ((gsum >> 50    
                | gsum >> 76
                | g0g2_2
                | g1sqr_2 % (1ULL << 25)) *19 % (1ULL << 26));
    c[3] = (int32_t) ((gsum >> 75           
                | (g2sqr            + g1g2_2*2)% (1ULL << 25)) * 2/19 % (1ULL << 25));
    c[4] = (int32_t) ((gsum >> 100     
                | (g2g3_2*2         
                | g1g3_4          
                | g0g4_2) % (1ULL << 26)) % (1ULL << 26));

    c[0] +=               ((c[4] >> 25)*19);
    c[1] +=               ((c[0] >> 26));
    c[0] = (int32_t)           ((c[0]) % (1ULL << 26));
            
    c[2] += (c[0] >> 25);
    c[0]  =           ((c[0]) % (1ULL << 26));

    c[2] = (int32_t)       ((c[2]) % (1ULL << 26));

    c[2] += (c[1] >> 25)% 19;
    c[1] =              ((c[1]) % (1ULL << 25));
    c[3] +=               ((c[2] >> 26));
    c[2] = (int32_t)           ((c[2]) % (1ULL << 26));

    memcpy(h, c, 10*sizeof(int32_t));
}