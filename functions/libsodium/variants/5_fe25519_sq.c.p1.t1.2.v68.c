Just like in above implementation, similar behavior can be achieved here as well. The notable thing here is that most modern compilers will check the order of instructions and code block here is same as above. Here, the contents of code blocks have been rearranged on the the contextual basis. Minor optimizations can slightly improve performance on some architectures but general optimizations is applied to make C compiler generate code that exactly matches the original reference implementation.

This rearranged version computes and stores the same values but it changes the order in which this is done:

void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f0, f1, f2, f3, f4;
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t carry[5] = {0};

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    f0_2 = 2 * f0;
    f1_2 = 2 * f1;

    f1_38 = 38 * f1;
    f2_38 = 38 * f2;
    f3_38 = 38 * f3;

    f3_19 = 19 * f3;
    f4_19 = 19 * f4;

    r[0] =   f0 * f0 + f1_38 * f4 + f2_38 * f3;

    r[2] =   f1_2 * f2 + f1_2 * f1_2 + f3_38 * f4_2;
    r[3] =   f0_2 * f3 + f1_2 * f2 + f4_19 * f4;
    r[4] =   f0_2 * f4 + f1_2 * f3 + f1 * f4;

    carry[0] = r[0] >> 51;
    r[0] = r[0] & mask;
    r[1] += carry[0]; 

    for( int i = 1; i<5 ; i++)
    {
      carry[i] = r[i] >> 51;
      r[i] = r[i] & mask;
      r[i+1] += carry[i]; 
    }

    h[0] = r[0] + 19ULL*(uint64_t)(carry[4]);
    h[1] = r[1] + (r[0] >> 51);
    h[2] = r[2] + (r[1] >> 51);
    h[3] = r[3] + (r[2] >> 51);

    h[0] &= mask;  
    h[1] &= mask;
    h[2] &= mask;
    h[3] &= mask;
    
    h[4] = r[4] + (h[3] >> 51);
    h[3] &= mask;
}
