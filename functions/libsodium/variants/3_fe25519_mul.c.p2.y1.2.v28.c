void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t var_f[10];
    int32_t var_g[10];

    for (int i = 0; i < 10; i++)
    {
        var_f[i] = f[i];
        var_g[i] = g[i];
    }

    int32_t g1_19 = 19 * var_g[1];
    int32_t g2_19 = 19 * var_g[2];
    int32_t g3_19 = 19 * var_g[3];
    int32_t g4_19 = 19 * var_g[4];
    int32_t g5_19 = 19 * var_g[5];
    int32_t g6_19 = 19 * var_g[6];
    int32_t g7_19 = 19 * var_g[7];
    int32_t g8_19 = 19 * var_g[8];
    int32_t g9_19 = 19 * var_g[9];
    int32_t f1_2  = 2 * var_f[1];
    int32_t f3_2  = 2 * var_f[3];
    int32_t f5_2  = 2 * var_f[5];
    int32_t f7_2  = 2 * var_f[7];
    int32_t f9_2  = 2 * var_f[9];

    int64_t h_vals[10];
    int64_t carry[10];

    for (int i = 0; i < 10; ++i) 
    {
        h_vals[i] = 0;
        for (int j = 0; j <= i; ++j) 
        {
            int k = i - j;
            if (j & 1 && k & 1) 
            {
                if (j & 2) h_vals[i] += (((j+1)/2) * 38 * (int64_t)g9_19) * var_f[k];
                else h_vals[i] += (((j+1)/2) * 19 * (int64_t)var_f[k]) * g9_19;
            } 
            else 
            {
              if(j == 0 || j == 9) h_vals[i] += var_f[j] * (int64_t) var_g[k];
              else h_vals[i] += (j/2 + j % 2) * (int64_t) var_f[j] * var_g[k];
            }
        }
        if(i == 0 || i == 2 || i == 4 || i == 6 || i ==8) h_vals[i] = (h_vals[i] + (int64_t)(1L << 25)) >> 26;
        else h_vals[i] = (h_vals[i] + (int64_t)(1L << 24)) >> 25;
    }
  
    h_vals[1] += carry[0]; 
    h_vals[5] += carry[4]; 

    carry[1] = h_vals[0] >> 26; h[0] = h_vals[0] - carry[1] * ((uint64_t) 1L << 26);
    carry[5] = h_vals[4] >> 26; h[4] = h_vals[4] - carry[5] * ((uint64_t) 1L << 26);

    h_vals[2] += carry[1]; 
    h_vals[6] += carry[5]; 

    carry[2] = h_vals[1] >> 25; h[1] = h_vals[1] - carry[2] * ((uint64_t) 1L << 25);
    carry[6] = h_vals[5] >> 25; h[5] = h_vals[5] - carry[6] * ((uint64_t) 1L << 25);

    h_vals[3] += carry[2]; 
    h_vals[7] += carry[6]; 

    carry[3] = h_vals[2] >> 26; h[2] = h_vals[2] - carry[3] * ((uint64_t) 1L << 26);
    carry[7] = h_vals[6] >> 26; h[6] = h_vals[6] - carry[7] * ((uint64_t) 1L << 26);

    h_vals[4] += carry[3]; 
    h_vals[8] += carry[7]; 

    carry[4] = h_vals[3] >> 25; h[3] = h_vals[3] - carry[4] * ((uint64_t) 1L << 25);
    carry[8] = h_vals[7] >> 25; h[7] = h_vals[7] - carry[8] * ((uint64_t) 1L << 25);

    h_vals[5] += carry[4];  
    h_vals[9] += carry[8];  
    
    carry[9] = h_vals[8] >> 26; h[8] = h_vals[8] - carry[9] * ((uint64_t) 1L << 26);

    h_vals[0] += carry[9] * 19;

    carry[0] = h_vals[9] >> 25; h[9] = h_vals[9] - carry[0] * ((uint64_t) 1L << 25);

    h[0] = (h[0] + ((carry[0] & (int64_t)(1))<<(25)) & 0xFFFFFFFF)
}