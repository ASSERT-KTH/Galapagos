fe25519_mul(fe25519 h, const fe25519 f, const fe2559 g)
{
    int64_t t[10];
    int32_t f0=f[0], f1=f[1], f2=f[2], f3=f[3], f4=f[4], 
            f5=f[5], f6=f[6], f7=f[7], f8=f[8], f9=f[9];
    int32_t g0=g[0], g1=g[1], g2=g[2], g3=g[3], g4=g[4],
            g5=g[5], g6=g[6], g7=g[7], g8=g[8], g9=g[9];
    
    int32_t g1_19 = 19 * g1;
    int32_t g2_19 = 19 * g2;
    int32_t g3_19 = 19 * g3;
    int32_t g4_19 = 19 * g4;
    int32_t g5_19 = 19 * g5;
    int32_t g6_19 = 19 * g6;
    int32_t g7_19 = 19 * g7;
    int32_t g8_19 = 19 * g8;
    int32_t g9_19 = 19 * g9;
    int32_t f1_2 = 2 * f1;
    int32_t f3_2 = 2 * f3;
    int32_t f5_2 = 2 * f5;
    int32_t f7_2 = 2 * f7;
    int32_t f9_2 = 2 * f9;
    for(int i = 0; i < 10; i++){
        if(i == 0){
            t[i] = f0 * (int64_t) g0;
            t[i] += f1_2 * (int64_t) g9_19;
            t[i] += f2 * (int64_t) g8_19;
            //do other operations
        } else if(i == 1){
            t[i] = f0 * (int64_t) g1;
            t[i] += f1 * (int64_t) g0;
            //do other operations
        }
        // continue implementing the rest of the operation
    }

    int64_t carry[10];
    for(int i = 0; i < 10; i++){
        if(i == 1 || i== 3 || i == 5 || i == 7 || i == 9){
            t[i] = (t[i] + (int64_t)(1L << 24)) >> 25;
            t[i+1] += t[i];
            t[i] -= t[i] * ((uint64_t) 1L << 25);
        }
        else{
            t[i] = (t[i] + (int64_t)(1L << 25)) >> 26;
            t[i+1] += t[i];
            t[i] -= t[i] * ((uint64_t) 1L << 26);
            i++;
        }
    }
    for(int i = 0; i<10; i++){
        carry[i] = t[i];
        h[i] = (int32_t) carry[i];
    }
}