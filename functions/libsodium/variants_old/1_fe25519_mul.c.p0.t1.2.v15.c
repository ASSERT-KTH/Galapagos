fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t g1_19 = 19 * g[1];
    int32_t g2_19 = 19 * g[2];
    int32_t g3_19 = 19 * g[3];
    int32_t g4_19 = 19 * g[4];
    int32_t g5_19 = 19 * g[5];
    int32_t g6_19 = 19 * g[6];
    int32_t g7_19 = 19 * g[7];
    int32_t g8_19 = 19 * g[8];
    int32_t g9_19 = 19 * g[9];
    int32_t f1_2  = 2 * f[1];
    int32_t f3_2  = 2 * f[3];
    int32_t f5_2  = 2 * f[5];
    int32_t f7_2  = 2 * f[7];
    int32_t f9_2  = 2 * f[9];

    int64_t products[100];
    for(int i=0; i<256/32; i++)
        for(int j=0; j<=i; j++)
        {
            int64_t coefficient = (i==j) ? 1 : 2;
            if(i+j>=2 && (i+j)%2==0)
                coefficient *= 19;
            products[i+j+32] = f[i]*coefficient*g[j];
        }

    int64_t sums[10];
    for(int i=0; i<5; i++)
    {
        sums[i*2] = products[i*32] + products[i*32+3] + products[i*32+6] + products[i*32+9] + products[i*32+16] + products[i*32+19]  + products[i*32+24] + products[i*32+27] + products[i*32+34]  + products[i*32+37];
        sums[i*2+1] = products[i*32+1] + products[i*32+4] + products[i*32+8] + products[i*32+13] + products[i*32+18] + products[i*32+26] + products[i*32+33] + products[i*32+38];
    }

    int32_t carry[10] = {0};

    for(int i=0; i<9; i++)
    {
        carry[i] = (sums[i]+(1L<<(24+(i%2)))) >> (25+(i%2));
        sums[i+1] += carry[i];
        sums[i] -= carry[i] << (25+(i%2));
    }

    carry[9] = (sums[9] + (int64_t)(1L << 24)) >> 25;
    sums[0] += carry[9] * 19;
    sums[9] -= carry[9] * ((uint64_t) 1L << 25);
    carry[0] = (sums[0] + (int64_t)(1L << 25)) >> 26;
    sums[1] += carry[0];
    sums[0] -= carry[0] * ((uint64_t) 1L << 26);

    for(int i=0; i<10; i++)
        h[i] = sums[i];
}