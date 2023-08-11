The following code accomplishes the same function with a bit of trivial adjustments to sum things up before make carry computations, transforming repeated code into a loop. It does not use standard library or other sub-function calls to maintain the integrity and independence of the function.


void fe25519_sq(int32_t* h, const int32_t* f)
{
    int32_t f0_2  = 2 * f[0];
    int32_t f1_2  = 2 * f[1];
    int32_t f2_2  = 2 * f[2];
    int32_t f3_2  = 2 * f[3];
    int32_t f4_2  = 2 * f[4];
    int32_t f5_2  = 2 * f[5];
    int32_t f6_2  = 2 * f[6];
    int32_t f7_2  = 2 * f[7];
    int32_t f5_38 = 38 * f[5];
    int32_t f6_19 = 19 * f[6];
    int32_t f7_38 = 38 * f[7];
    int32_t f8_19 = 19 * f[8];
    int32_t f9_38 = 38 * f[9];

    int64_t fterms[10][10] = 
    {
      { f[0] * (int64_t) f[0], f0_2 * (int64_t) f[1], f0_2 * (int64_t) f[2], f0_2 * (int64_t) f[3], f0_2 * (int64_t) f[4], f0_2 * (int64_t) f[5], f0_2 * (int64_t) f[6], f0_2 * (int64_t) f[7], f0_2 * (int64_t) f[8], f0_2 * (int64_t) f[9], },
      { f1_2 * (int64_t) f[1], f1_2 * (int64_t) f[2], f1_2 * (int64_t) f[3], f1_2 * (int64_t) f[4], f1_2 * (int64_t) f[5], f1_2 * (int64_t) f[6], f1_2 * (int64_t) f[7], f1_2 * (int64_t) f[8], f1_2 * (int64_t) f9_38 },
      { f[2] * (int64_t) f[2], f2_2 * (int64_t) f[3], f2_2 * (int64_t) f[4], f2_2 * (int64_t) f[5], f2_2 * (int64_t) f[6], f2_2 * (int64_t) f[7], f2_2 * (int64_t) f8_19, f[2] * (int64_t) f9_38 },
      { f3_2 * (int64_t) f[3], f3_2 * (int64_t) f[4], f3_2 * (int64_t) f[5], f3_2 * (int64_t) f[6], f3_2 * (int64_t) f7_38, f3_2 * (int64_t) f8_19, f3_2 * (int64_t) f9_38, },
      { f[4] * (int64_t) f[4], f4_2 * (int64_t) f[5], f4_2 * (int64_t) f6_19, f[4] * (int64_t) f7_38, f4_2 * (int64_t) f8_19, f[4] * (int64_t) f9_38, },
      { f[5] * (int64_t) f5_38, f5_2 * (int64_t) f6_19, f5_2 * (int64_t) f7_38, f5_2 * (int64_t) f8_19, f5_2 * (int64_t) f9_38, },
      { f[6] * (int64_t) f6_19, f[6] * (int64_t) f7_38, f6_2 * (int64_t) f8_19, f[6] * (int64_t) f9_38, },
      { f[7] * (int64_t) f7_38, f7_2 * (int64_t) f8_19, f7_2 * (int64_t) f9_38 },
      { f[8] * (int64_t) f8_19, f[8] * (int64_t) f9_38, },
      { f[9] * (int64_t) f9_38 }
    };

    int64_t h_element[10][10] = { 0 };
    int64_t hval[10] = { 0 };
    for (int row = 0; row < 10; ++row)
    {
        int cnt = row;
        for (int col = 9; col >= 0 && cnt < 10; --col, ++cnt)
        {
          hval[col] += fterms[row][cnt];
        }
    }

    int64_t carry = 0;
    for (int i = 0; i < 10; i += 2)
    {
        carry    = (hval[i] + (int64_t)((i+1 == 9)?1L << 24:1L << 25)) >> 26;
        hval[i+1] += carry;
        hval[i] -= carry << 26;
        carry    = ((hval[i+1] + (int64_t)(1L << 24)) >> 25) << 25;
        hval[(i+2)%10] += i+1==9?carry*19:carry;
        hval[i+1] -= carry;
    }
    for (int i = 0; i < 10; i++)
      h[i] = (int32_t)(hval[i]);
    
}

This alternative approach should give equivalent results to the original method.