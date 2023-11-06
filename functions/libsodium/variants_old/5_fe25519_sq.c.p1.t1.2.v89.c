You can write a program version that moves constant declarations and multiplies by these constants to for-loops. Although for-loops usually represent unnecessarily expensive operations compared to simple multiplications, in this case functionality remains the same and the behavior changes because CPU will perform multiple harmless estimations "38ULL * 1", "38ULL * 2" etc. instead of estimation of multipliers once. Here is what it might look like:


fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint128_t f[5];
    uint128_t fX_2[2];
    unsigned short i;
    
    uint128_t   r0, r1, r2, r3, r4;
    uint128_t rX_38[3], rX_19[2], carry;

    unsigned short multiplier_38 = 0, multiplier_19 = 0;
    for(i=0; i<5; i++)
    {
        f[i] = (uint128_t)f[i] ; //Typecast once and then use it so it doesn't have to typecast before each arithmetic operation

        if(i<2) //Calculate f0_2, f1_2 
        {
            fX_2[i] = f[i] << 1;
        }

        if(i<3) //Calculate f1_38, f2_38,f3_38 i.e multipliers for f[1],f[2]
        {
            multiplier_38 += 38ULL;
            rX_38[i] = multiplier_38 * f[i + 1]; 
        }

        if(i>0 && i<3) //Calculate  f3_19,f4_19  i.e multipliers for f[3],f[4]
        {
            multiplier_19 += 19ULL;
            rX_19[i - 1] = multiplier_19 * f[i + 2];
        }
    }

    r0 =   f[0] * f[0] + rX_38[0] * f[4] + rX_38[1] * f[3];
    r1 = fX_2[0] * f[1] + rX_38[0] * f[4] + rX_19[0] * f[3];
    r2 = fX_2[0] * f[2] +       f[1] * f[1] + rX_38[2] * f[4];
    r3 = fX_2[0] * f[3] + fX_2[1] * f[2] + rX_19[1] * f[4];
    r4 = fX_2[0] * f[4] + fX_2[1] * f[3] +             f[2] * f[2];

    uint64_t h_temp[5] = {r0, r1, r2, r3, r4};
    for (i = 0; i < 4; i++)
    {
        h_temp[i] &= 0x7ffffffffffffULL;
        carry = h_temp[i] >> 51;
        h_temp[i + 1] += carry;
    }

    carry = h_temp[4] >> 51;
    h_temp[4] &= 0x7ffffffffffffULL;
    h_temp[0] += 19ULL * carry;
    h_temp[1] += h_temp[0] >> 51;
    h_temp[0] &= 0x7ffffffffffffULL;
    h_temp[2] += h_temp[1] >> 51;
    h_temp[1] &= 0x7ffffffffffffULL;

    for (i = 0; i < 5; i++)
    {
        h[i] = h_temp[i];
    }
}

Note: Above C code has transformed calculations with constants (i.e., multiplied with 19 or 38 or scaled by 2) using increment-for-loop but maintaining original functionality. End-results would remain the same no matter what happens underneath transformations enhancing "obfuscated" form suitable for cryptography applications.