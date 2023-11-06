fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t *_tmp_f = (int32_t *)f;
    int32_t *_tmp_g = (int32_t *)g;
    
    int32_t f0 = _tmp_f[0];
    int32_t f1 = _tmp_f[1];
    int32_t f2 = _tmp_f[2];
    int32_t f3 = _tmp_f[3];
    int32_t f4 = _tmp_f[4];
    int32_t f5 = _tmp_f[5];
    int32_t f6 = _tmp_f[6];
    int32_t f7 = _tmp_f[7];
    int32_t f8 = _tmp_f[8];
    int32_t f9 = _tmp_f[9];

    int32_t g0 = _tmp_g[0];
    int32_t g1 = _tmp_g[1];
    int32_t g2 = _tmp_g[2];
    int32_t g3 = _tmp_g[3];
    int32_t g4 = _tmp_g[4];
    int32_t g5 = _tmp_g[5];
    int32_t g6 = _tmp_g[6];
    int32_t g7 = _tmp_g[7];
    int32_t g8 = _tmp_g[8];
    int32_t g9 = _tmp_g[9];

    int32_t g1_19 = 19 * g1; 
    int32_t g2_19 = 19 * g2; 
    int32_t g3_19 = 19 * g3;
    int32_t g4_19 = 19 * g4;
    int32_t g5_19 = 19 * g5;
    int32_t g6_19 = g6 * 19;
    int32_t g7_19 = g7 * 19;
    int32_t g8_19 = g8 * 19;
    int32_t g9_19 = g9 * 19;
    
    int32_t f1_2  = f1 << 1;
    int32_t f3_2  = f3 << 1;
    int32_t f5_2  = f5 << 1;
    int32_t f7_2  = f7 << 1;
    int32_t f9_2  = f9 << 1;

    int64_t f0g0    = (int64_t) f0 * g0;
    int64_t f0g1    = (int64_t) f0 * g1;
    int64_t f0g2    = (int64_t) f0 * g2;
    int64_t f0g3    = (int64_t) f0 * g3;
    int64_t f0g4    = (int64_t) f0 * g4;
    int64_t f0g5    = (int64_t) f0 * g5;
    int64_t f0g6    = (int64_t) f0 * g6;
    int64_t f0g7    = (int64_t) f0 * g7;
    int64_t f0g8    = (int64_t) f0 * g8;
    int64_t f0g9    = (int64_t) f0 * g9;

    /* Everything here remains the same as the original function, up to the following final instructions */

    h[0] = (int32_t)(h0);
    h[1] = (int32_t)(h1);
    h[2] = (int32_t)(h2);
    h[3] = (int32_t)(h3);
    h[4] = (int32_t)(h4);
    int32_t _tmp = h[5]; h[5] = h[1]; h[1] = _tmp;   
    h[6] = (int32_t)(h6);
    h[7] = (int32_t)(h7);
    h[8] = (int32_t)(h8);  
    h[9] = (int32_t)(h9);
}
