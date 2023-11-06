// Variation 1: Using for loop for array masking
void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_int[10];
    int32_t g_int[10];
    
    for (int i = 0; i < 10; i++)
    {
        f_int[i] = f[i];
        g_int[i] = g[i];
    }
    
    int32_t g19[10], f2[10];
    for (int i = 1; i < 10; i++)
    {
        g19[i] = 19 * g_int[i];
        if (i % 2 != 0)
             f2[i] = 2 * f_int[i];
    }

    int32_t fflg0[10] = {f2[5], f_int[6], f2[7], f_int[8], f_int[9]};
    int32_t fflg1[10] = {g_int[6], g19[7], g_int[8], g19[9]};
    int64_t ffg[10];
    for (int i=0; i<10; i++)
    {
         ffg[i] = f_int[i] * (int64_t) g_int[0];
         int j = (i + 1) % 10;
         if (j % 2 != 0)
         {
             ffg[i] += f2[j] * (int64_t) g19[i+1];
             ffg[i] += f_int[++j] * (int64_t) fflg0[(j-2)/2];
         }
         int k = j + 1;
         for(; k<10;)
         {
             ffg[i] += fflg0[(k-2)/2] * (int64_t) fflg1[(k-3)/2];
             if (++k >= 10)
                 break;
             if (++k >= 10)
                 break;
         }
         if (ffg[i] <0)
             ffg[i] = - ffg[i];
    }
    int64_t carry[10];
    int64_t h_temp[10];
    for (int i = 0; i < 10; i++)
    {
        int j = (i + 1) % 10;
        carry[i] = (ffg[i] + (int64_t)(1L << (26 - i % 2))) >> (26 - i % 2); 
        h_temp[i] = ffg[j] + carry[i];
        h_temp[i] -= carry[i] * ((uint64_t) 1L << (26 - i % 2));
    }
    carry[9] = (h_temp[9] + (int64_t)(1L << 24)) >> 25;
    h_temp[0] += carry[9] * 19;
    h_temp[9] -= carry[9] * ((uint64_t) 1L << 25);
    carry[0] = (h_temp[0] + (int64_t)(1L << 25)) >> 26;
    h_temp[1] += carry[0];
    h_temp[0] -= carry[0] * ((uint64_t) 1L << 26);

    for (int i=0; i < 10; i++)
    {
        h[i] = (int32_t) h_temp[i];
    }
}