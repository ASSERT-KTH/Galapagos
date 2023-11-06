void fe25519_sq(fe25519 h, const fe25519 f)
{ 
    int64_t f0 = (int64_t) f[0];
    int64_t f1 = (int64_t) f[1];
    int64_t f2 = (int64_t) f[2];
    int64_t f3 = (int64_t) f[3];
    int64_t f4 = (int64_t) f[4];
    int64_t f5 = (int64_t) f[5];
    int64_t f6 = (int64_t) f[6];
    int64_t f7 = (int64_t) f[7];
    int64_t f8 = (int64_t) f[8];
    int64_t f9 = (int64_t) f[9];

    int64_t f_ARR[5][4] = {
        {f0 * 2,     f1 * 2,     f2 * 2,     f3 * 2    },
        {f1_2 * f3_2,f1_2 * f5_2,f1_2 * f7_2,f1_2 * f9_2 },
        {f2_2 * f3,   f2_2 * f5,   f2_2 * f6,   f2_2 * f7   },
        {f3_2 * f5_2,f3_2 * f7_2,f3_2 * f9_2,0 },
        {f4 * 38, f5_38 * f5,   f6_19 * f6, f7_38 * f5 }
    };

    // precompute
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 3 - (i == 4); j++) {
            f_ARR[i][j + 1] += f_ARR[i][j] >> 25;
            f_ARR[i][j ] &= 0x1ffffff;
        }
    }

    for(int i = 18; i > 0; i-=2) {
        int u = i | 1;
        int64_t w = (f_ARR[u / 4][u % 4] + 5) >> 2;
        
        int64_t t = w + ((f_ARR[u / 4][u % 4] * 2) & 3);
        out[u / 2] = t;
        
        int v = i - 1;
        int64_t z = (f_ARR[v / 4][v % 4] + 2) >> 3;
        f_ARR[v / 4][v %4] -= z * 5;
        out[v / 2] = f_ARR[v / 4][v % 4];
        
        out[(v / 2) - 5] += z;
        out[v / 2] *= 2;
    }
    
    {
        int u = 0;
        int64_t w = (f_ARR[u / 4][u % 4] + 5) >> 2;
        int64_t t = w + ((f_ARR[u / 4][u % 4] * 2) & 3);
        out[u / 2] = t % (1LL << 26);
        
        int v = 19;
        int64_t z = (f_ARR[v - 5][3] + 2) >> 3;
    
        f_ARR[v / 4][v %4] -= z * 5;
        out[v / 2] = (int)(f_ARR[v / 4][v % 4]);
    
        out[(v / 2) - 1] += z;
    }  
}