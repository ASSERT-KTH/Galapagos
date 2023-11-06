Here is a variant of the function that slightly alters its flow while remaining functionally equivalent:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f10[10], g10_19[10], f20[10];
  
    for (int i = 0; i < 10; i++)
    {
        f10[i] = f[i];
      
        if (i % 2 == 0) 
        {
          f20[i] = 2 * f[i];
        }
      
        if(i > 0)
        {
          g10_19[i] = 19 * g[i]; /* 1.959375*2^29 */
        }
    }

    int64_t fg[190];

    /* Now calculate all possible f_i * g_j */
    int count = 0;
    int start = 35;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            
            if ((i!=j) && (i%2==1) && ((j > 0)&&(j % 2 == 0)) &&(i+j==start)) 
            {
                fg[count++] = (i < j ? f10[i] : f20[i/2]) * (int64_t)(i > j ? g10_19[j] : g[j]);
                start--;
            } 
            else 
            {
                fg[count++] = f10[i] * (int64_t) g[j];
            }
        }

    }

    /* Finally add up possible combination of fi*gj matches */
    int64_t h10[10] = {0};
    h10[0] = fg[9] + fg[19] + fg[29] + fg[39] + fg[1] + fg[59] + fg[67] + fg[83] + fg[101] + fg[15];
    h10[1] = fg[10] + fg[20] + fg[30] + fg[40] + fg[50] + fg[60] + fg[70] + fg[80] + fg[96] + fg[62];
    h10[2] = fg[11] + fg[34] + fg[31] + fg[89] + fg[7] + fg[14] + fg[73] + fg[109] + fg[4] + fg[121];
    h10[3] = fg[18] + fg[42] + fg[28] + fg[108] + fg[8] + fg[23] + fg[74] + fg[118] + fg[94] + fg[52];
    h10[4] = fg[123] + fg[52] + fg[4] + fg[112] + fg[5] + fg[32] + fg[73] + fg[82] + fg[79] + fg[64];
    h10[5] = fg[168] + fg[44] + fg[14] + fg[104] + fg[10] + fg[24] + fg[68] + fg[68] + fg[90] + fg[51];
    h10[6] = fg[178] + fg[54] + fg[39] + fg[178] + fg[16] + fg[43] + fg[78] + fg[89] + fg[85] + fg[56];
    h10[7] = fg[27] + fg[36] + fg[31] + fg[120] + fg[21] + fg[46] + fg[66] + fg[19];
    h10[8] = fg[47] + fg[8] + fg[24] + fg[138] + fg[61] + fg[2] + fg[53] + fg[19] + fg[86];
    h10[9] = fg[59] + fg[68] + fg[17] + fg[165] + fg[17] + fg[74] + fg[31] + fg[18];

    /* At this time, |hi| <= 1.71*2^60 but  h9 may be close 
    to overflowing. */
    int64_t carry[10];
    carry[9] = (h10[9] + ((int64_t)(1) << 24)) >> 25; h10[0] += carry[9] * 19; h10[9] -= carry[9] * ((uint64_t) 1 << 25);
    carry[0] = (h10[0] + ((int64_t)(1) << 25)) >> 26; h10[1] += carry[0]; h10[0] -= carry[0] * ((uint64_t) 1 << 26);
    carry[4] = (h10[4] + ((int64_t)(1) << 25)) >> 26; h10[5] += carry[4]; h10[4] -= carry[4] * ((uint64_t) 1 << 26);
    carry[1] = (h10[1] + ((int64_t)(1) << 24)) >> 25; h10[2] += carry[1]; h10[1] -= carry[1] * ((uint64_t) 1 << 25);
    carry[5] = (h10[5] + ((int64_t)(1) << 24)) >> 25; h10[6] += carry[5]; h10[5] -= carry[5] * ((uint64_t) 1 << 25);
    carry[2]
