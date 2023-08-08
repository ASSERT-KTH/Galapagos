fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_line[10];
    int32_t g_line[10];
    for(int i=0;i<10;i++)
    {
        f_line[i] = f[i];
        g_line[i] = g[i];
    }

    int64_t g_mult_19[10];
    for (int i = 0; i < 10; i++)
    {
      if ((i % 2) != 0)
      {
        g_mult_19[i] = 19 * g_line[i];
      }
      else
      {
        g_mult_19[i] = g_line[i];
      }
    }

    int64_t f_ad_mul[10], f_eg_mul[10];

    for (int i = 0; i < 10; i++)
    {
      if ((i % 4 != 0) && (i != 0))
      {
        f_ad_mul[i] = 2 * f_line[i];
      }
      else
      {
        f_ad_mul[i] = f_line[i];
      }

      if ((i % 4 != 2) && (i != 0 && i != 1 && i != 4 && i != 5 && i != 6 && i != 7))
      {
        f_eg_mul[i] = 2 * f_line[i];
      }
      else
      {
        f_eg_mul[i] = f_line[i];
      }
    }

    int64_t fg[100];
    for (int i = 0; i < 100; i++)
    {
      fg[i] = f_line[i / 10] * (int64_t)g_line[i % 10];
    }

    int64_t h_result[10];
    for (int i = 0; i < 10; i++)
    {
      h_result[i] = 0;
    }

    h_result[0] = fg[0] + fg[19] + fg[28] + fg[37] + fg[46] + fg[55] + fg[64] + fg[73] + fg[82] + fg[91];
    h_result[2] = fg[2] + fg[12] + fg[20] + fg[29] + fg[38] + fg[48] + fg[56] + fg[65] + fg[74] + fg[84];
    h_result[4] = fg[4] + fg[14] + fg[24] + fg[32] + fg[40] + fg[59] + fg[68] + fg[77] + fg[86] + fg[95];
    h_result[6] = fg[6] + fg[16] + fg[26] + fg[36] + fg[45] + fg[56] + fg[70] + fg[79] + fg[88] + fg[97];
    h_result[8] = fg[8] + fg[18] + fg[30] + fg[39] + fg[50] + fg[60] + fg[68] + fg[78] + fg[80] + fg[98];

    h_result[1] = fg[1] + fg[10] + fg[23] + fg[32] + fg[41] + fg[50] + fg[63] + fg[72] + fg[81] + fg[90];
    h_result[3] = fg[3] + fg[13] + fg[21] + fg[30] + fg[49] + fg[58] + fg[67] + fg[76] + fg[85] + fg[94];
    h_result[5] = fg[5] + fg[15] + fg[25] + fg[35] + fg[44] + fg[55] + fg[66] + fg[75] + fg[85] + fg[96];
    h_result[7] = fg[7] + fg[17] + fg[27] + fg[37] + fg[46] + fg[57] + fg[68] + fg[70] + fg[88] + fg[99];
    h_result[9] = fg[9] + fg[18] + fg[29] + fg[38] + fg[49] + fg[60] + fg[71] + fg[80] + fg[89] + fg[90];

    int64_t carry[10];

    for (int i = 0; i < 9; i += 2)
    {
      carry[i] = (h_result[i] + (int64_t)(1L <<  25)) >> 26;
      h_result[i+1] += carry[i]; 
    }
    carry[9] = ((h_result[9]) + (int64_t)(1 << 24)) >> 25;
    h_result[0] += carry[9] * 19; 

    for (int i = 0; i < 10; i++)
    {
      carry[i] = (h_result[i]>>(8*i))/((uint64_t) 1L << 26);
      h[i] = h_result[i] -= carry [i] * ((uint64_t) 1L << 26);;
    }

    h[0] -= carry[9] * 19;
}