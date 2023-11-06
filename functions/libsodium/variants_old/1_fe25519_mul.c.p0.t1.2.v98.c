fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_copy[10];
    int32_t g_copy[10];
    
    for(int i=0; i<10; i++){
        f_copy[i]=f[i];
        g_copy[i]=g[i];
    }
    
    int32_t f0 = f_copy[0];
    int32_t f1 = f_copy[1];
    int32_t f2 = f_copy[2];
    int32_t f3 = f_copy[3];
    int32_t f4 = f_copy[4];
    int32_t f5 = f_copy[5];
    int32_t f6 = f_copy[6];
    int32_t f7 = f_copy[7];
    int32_t f8 = f_copy[8];
    int32_t f9 = f_copy[9];

    int32_t g0 = g_copy[0];
    int32_t g1 = g_copy[1];
    int32_t g2 = g_copy[2];
    int32_t g3 = g_copy[3];
    int32_t g4 = g_copy[4];
    int32_t g5 = g_copy[5];
    int32_t g6 = g_copy[6];
    int32_t g7 = g_copy[7];
    int32_t g8 = g_copy[8];
    int32_t g9 = g_copy[9];

    // The rest of the code goes as it is...
}