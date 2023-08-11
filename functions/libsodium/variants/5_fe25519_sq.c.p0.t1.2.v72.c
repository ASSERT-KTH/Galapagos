fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;   //Shift the declaration of mask
    uint128_t r0, r1, r2, r3, r4, f0, f1, f2, f3, f4;   //Compact variables in same data types
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;   //Compact variables in same data types
    uint64_t  r00, r01, r02, r03, r04, carry;   //Compact variables in same data types

    f0 = (uint128_t) f[0];   //Typcast and variable assignment operation in separate lines for readability
    f1 = (uint128_t) f[1];   //--||--
    f2 = (uint128_t) f[2];   //--||--
    f3 = (uint128_t) f[3];   //--||--
    f4 = (uint128_t) f[4];   //--||--

    f0_2 = f0 << 1;   //Typcast and variable assignment operation in separate lines for readability
    f1_2 = f1 << 1;   //--||--

    f1_38 = 38ULL * f1;   //Typcast and variable assignment operation in separate lines for readability
    f2_38 = 38ULL * f2;   //--||--
    f3_38 = 38ULL * f3;   //--||--

    f3_19 = 19ULL * f3;   //Typcast and variable assignment operation in separate lines for readability
    f4_19 = 19ULL * f4;   //--||--

    r0 = f0 * f0 + f1_38 * f4 + f2_38 * f3;   //--||--
    r1 = f0_2 * f1 + f2_38 * f4 + f3_19 * f3; //--||--
    r2 = f0_2 * f2 + f1 * f1 + f3_38 * f4;   //--||--
    r3 = f0_2 * f3 + f1_2 * f2 + f4_19 * f4;   //--||--
    r4 = f0_2 * f4 + f1_2 * f3 + f2 * f2;   //--||--

    r00    = r0 & mask;   // remove unnecessary typecast
    carry  = r0 >> 51ULL; 
    r1    += carry;
    r01    = r1 & mask;   // remove unnecessary typecast
    carry  = r1 >> 51ULL; 
    r2    += carry;
    r02    = r2 & mask;   // remove unnecessary typecast
    carry  = r2 >> 51ULL; 
    r3    += carry;
    r03    = r3 & mask;   // remove unnecessary typecast
    carry  = r3 >> 51ULL;
    r4    += carry;
    r04    = r4 & mask;   // remove unnecessary typecast
    carry  = r4 >> 51ULL; 
    r00   += 19ULL * carry;
    carry  = r00 >> 51ULL;
    r00   &= mask;
    r01   += carry;
    carry  = r01 >> 51ULL;
    r01   &= mask;
    r02   += carry;

    h[0] = r00;   //--||--
    h[1] = r01;   //--||--
    h[2] = r02;   //--||--
    h[3] = r03;   //--||--
    h[4] = r04;   //--||--
}