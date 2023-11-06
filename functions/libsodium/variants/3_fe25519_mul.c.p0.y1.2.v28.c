void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t fVals[10], gVals[10];

    for (int index = 0; index < 10; index++) {
        fVals[index] = f[index];
        gVals[index] = g[index];
    }

    int32_t mods[10][2] = {
        {15 * 2,      19 * ((uint64_t) 1L << 24)},
        {(uint64_t) 1L << 25, 19 * 2},
        {15 * 2,      19 * ((uint64_t) 1L << 24)},
        {(uint64_t) 1L << 25, 19 * 2},
        {15 * 2,      19 * ((uint64_t) 1L << 24)},
    };

    int64_t hVals[5][2];

    for (int j = 0; j < 5; j++)
    {
        hVals[j][0] = fVals[2*j] * (int64_t) gVals[2*j];

        for (int k = 0; k < 5; k++)
        {
            hVals[j][0] += fVals[2*j+1] * (int64_t) gVals[9-2*k] * mods[k][0];
            hVals[j][0] += fVals[2*k] * (int64_t) gVals[2*j+1] * mods[k][0];
        
            if (j > 0)
            {        
                hVals[j][0] += (2 * fVals[2*j-1]) * (int64_t) gVals[10-2*k] * mods[k][1];
                hVals[j][0] += (2 * fVals[2*k-1]) * (int64_t) gVals[2*j] * mods[k][1];
            }    
        }

        hVals[j][1] = fVals[2*j+1] * (int64_t) gVals[2*j+1];
    
        for (int i = 0; i < 5; i++)
        {
            hVals[j][1] += (2 * fVals[2*j+2-2*(j>i)]) * (int64_t) gVals[2*i+1] * mods[i][1];
            hVals[j][1] += (2 * fVals[2*i]) * (int64_t) gVals[2*j+1+(j>i)] * mods[i][0];
        }   
    }

    int64_t carries[5][2] = {{25, 26}, {24, 25}, {25, 26}, {24, 25}, {25, 26}};
    
    for (int i = 0; i < 4; ++i)
    {
        hVals[i+1][0] += hVals[i][1] >> carries[i][1];
        hVals[i][1] &= (1 << carries[i][1])-1;

        hVals[i+1][1] += hVals[i][0] >> carries[i][0];
        hVals[i][0] &= (1 << carries[i][0])-1;
    }

    int64_t s = hVals[4][1] >> 24;
    hVals[4][1] &= (1 << 24)-1;

    s *= 19;
    hVals[0][0] += s;
    
    carries[0][0] = hVals[0][0] >> 26;
    hVals[1][0] += carries[0][0];
    hVals[0][0] -= carries[0][0] << 26;

    for (int i = 0; i < 10; i++)
    {
        h[i] = (i % 2 == 0) ? (int32_t) hVals[i/2][0] :  (int32_t) hVals[i/2][1];
    }
}