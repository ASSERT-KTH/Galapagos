void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t fVal[10] = {f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9]};
    int32_t gVal[10] = {g[0], g[1], g[2], g[3], g[4], g[5], g[6], g[7], g[8], g[9]};

    int64_t term[10][11] = {0};
    int64_t carry[10] = {0};

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j< 10; j++)
        {
            if(i+j > i && j != 0)
            {
                if(i & 1 == 0)
                {
                    term[i+j][i] = (i+j > i) * ((i & 1) + fVal[i/2]) * (
                                fVal[i] * (int64_ext) gVal[j]
                             + (fVal[(i+2)%10] * ((j-1)%2) * 2 + fVal[(i+1)%10] * ((j)%2) *2) * (int64_ext)(19 * gVal[(j-2)%10])
                             + fVal[i] * (int64_ext)(19 * gVal[(j-1)%10]));
                }
                else
                {
                    term[i+j][i] = (i+j > i) * 2 * fVal[i] * (int64_ext)(19 * gVal[j]);
                }
            }
            else
            {
                if(j&1 == 0 && i&1 == 0)
                {
                    term[i+j][i] = fVal[i & 1? i/2*2+1:i/2] * (int64_ext) (gVal[j & 1? j/2*2+1:j/2] + gVal[i==0?9:i-1] * 19 * (j & 1? 2 : 1));
                }
                else if(i&1 == 1 && j&1 == 1)
                {
                    term[i+j][i] = 2 * fVal[i / 2 * 2 + 1] * (int64_ext)(19 * gVal[j / 2 * 2 + 1]);
                }
            }
        }
    }

    for(int16_t i=0;i<10;i++)
    {
        int16_t s = 0;
        for(int16_t j =0;j<11;j++)
        {
            s+=term[j%10][i];
            h[i]=s & ((((int64_t)1<<26)-1)-((i==0?1:0)<<25));
            s = (s>> (26-(i==0)*1)) + term[(j+1)%10][i];
        }
        carry[i] = s;
    }

    h[0] += carry[0]*19 >> 26;
    h[1] += carry[1] >> 25;
    h[2] += carry[2] >> 26;
    h[3] += carry[3] >> 25;
    h[4] += carry[4] >> 26;
    h[5] += carry[5] >> 25;
    h[6] += carry[6] >> 26;
    h[7] += carry[7] >> 25;
    h[8] += carry[8] >> 26;
    h[9] += carry[9] >> 25;
}