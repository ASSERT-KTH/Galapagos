fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[0];
    int32_t f1 = f[1];
    int32_t f2 = f[2];
    int32_t f3 = f[3];
    int32_t f4 = f[4];
    int32_t f5 = f[5];
    int32_t f6 = f[6];
    int32_t f7 = f[7];
    int32_t f8 = f[8];
    int32_t f9 = f[9];

    int64_t f0f0    = (int64_t)f0 * f0;
    int64_t f2f2    = f2 * (int64_t) f2;
    int64_t f3f3_2  = 2 * f3 * (int64_t) f3;
    int64_t f4f4    = f4 * (int64_t) f4;
    int64_t f5f5_38 = 38 * f5 * (int64_t) f5;
    int64_t f6f6_19 = 19 * f6 * (int64_t) f6;
    int64_t f7f7_38 = 38 * f7 * (int64_t) f7;
    int64_t f8f8_19 = 19 * f8 * (int64_t) f8;
    int64_t f9f9_38 = 38 * f9 * (int64_t) f9;
    
    int32_t t0 = 2 * f0, t1 = 2 * f1, t2 = 2 * f2, t3 = 2 * f3, t4 = 2 * f4;
    int32_t t5 = 2 * f5, t6 = 2 * f6, t7 = 2 * f7, t9_38 = 38 * f9, t8_19 = 19 * f8;
    int32_t F5_38 = 38 * f5, F6_19 = 19 * f6, F7_38 = 38 * f7;
    
    int64_t f0f1_2  = t0 * (int64_t) f1, f0f2_2  = t0 * (int64_t) f2;
    int64_t f1f1_2  = t1 * (int64_t) f1, f1f2_2  = t1 * (int64_t) f2;
    int64_t f2f4_2  = t2 * (int64_t) f4, f3f5_4  = t3 * (int64_t) t5;
    int64_t f0f5_2  = t0 * (int64_t) f5, f1f4_2  = t1 * (int64_t) f4;/td>
    int64_t f2f8_38 = t2 * (int64_t) t8_19, f3f7_76  = t3 * (int64_t) F7_38;
    int64_t f4f6_38 = t4 * (int64_t) F6_19, f0f3_2  = t0 * (int64_t) f3;
    
    
    
    int64_t h0 = f0f0 + f1f9_76 + f2f8_38 + f3f7_76 + f4f6_38 + f5f5_38;
    int64_t h1 = f0f1_2 + f2f9_38 + f3f8_38 + f4f7_38 + f5f6_38;
    int64_t h2 = f0f2_2 + f1f1_2 + f3f9_76 + f4f8_38 + f5f7_76 + f6f6_19;
    int64_t h3 = f0f3_2 + f1f2_2 + f4f9_38 + f5f8_38 + f6f7_38;
    int64_t h4 = f0f4_2 + f1f3_4 + f2f2 + f5f9_76 + f6f8_38 + f7f7_38;

    // etc... till h9 = f0f9_2 + f1f8_2 + f2f7_2 + f3f6_2 + f4f5_2;
    
    reduce_degree(h);

    h[0] = (int32_t) h[0];
    h[1] = (int32_t) h[1];
    h[2] = (int32_t) h[2];//the same for other elements from h[0] to h[9]
}

// A helper function to reduce the degree of intermediate results
void reduce_degree(int64_t* re)
{
    
    int64_t mask = (1LL << 52) - 1;
 
    re[0] += 19 * (re[9] >> 26);
    re[9] &= mask;

    for (int i = 0; i < 9; ++i) {
        re[i+1] += re[i] >> 26;
        re[i] &= mask;
    }

    re[0] += 19 * (re[9] >> 26);
    re[9] &= mask;
}