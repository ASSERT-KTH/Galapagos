fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t fvals[10];
    int32_t gvals[10];

    for(int i=0; i<10; i++) {
        fvals[i] = f[i];
        gvals[i] = g[i];
    }

    int32_t g1_19 = 19 * gvals[1]; 
    int32_t g2_19 = 19 * gvals[2]; 
    int32_t g3_19 = 19 * gvals[3];
    int32_t g4_19 = 19 * gvals[4];
    int32_t g5_19 = 19 * gvals[5];
    int32_t g6_19 = 19 * gvals[6];
    int32_t g7_19 = 19 * gvals[7];
    int32_t g8_19 = 19 * gvals[8];
    int32_t g9_19 = 19 * gvals[9];
    int32_t f1_2  = 2 * fvals[1];
    int32_t f3_2  = 2 * fvals[3];
    int32_t f5_2  = 2 * fvals[5];
    int32_t f7_2  = 2 * fvals[7];
    int32_t f9_2  = 2 * fvals[9];

    int64_t f0g0 = fvals[0] * (int64_t) gvals[0];
    int64_t f1g1_2  = f1_2 * (int64_t) gvals[1];
    int64_t h1 = f1g1_2;
    
    for(int idx=1; idx<10; idx++)  {
        int64_t f0gi  = fvals[0] * (int64_t) gvals[idx];
        int64_t fig0  = fvals[idx] * (int64_t) gvals[0];
        h1 += f0gi + fig0;
        
        if(idx%2 == 0) {
            int64_t f2g2 = fvals[idx] * (int64_t) gvals[idx];
            h1 += f2g2;
        } else { 
            int64_t fig_2  = 2 * fvals[idx] * (int64_t) gvals[idx];
            h1 += fig_2;
        }  
    }

    int64_t carry1 = (h1 + (int64_t)(1L << 24)) >> 25;
    int64_t temp  = carry1  * ((uint64_t) 1L << 25);

    h[1] = (int32_t)(h1 - temp);
}
