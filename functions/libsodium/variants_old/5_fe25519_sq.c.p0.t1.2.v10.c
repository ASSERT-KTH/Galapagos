fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t p0, p1, p2, p4, p3;
    uint128_t fd0, fd1, d1_2, fd2, d2_19, fd3, d3_38, d3_19, fd4, d4_38, d0_2;
    uint64_t result0, result1, result2, result3, result4;
    uint64_10 carry;

    fd0 = (uint128_t) f[0];
    fd1 = (uint128_t) f[1];
    fd2 = (uint128_t) f[2];
    fd3 = (uint128_t) f[3];
    fd4 = (uint128_t) f[4];

       
    d1_2  = fd1 << 1;
    d0_2  = fd0 << 1;


    d1_38  = 38ULL * df1;
    d2_38  = 38ULL * fd2;
    d3_38  = 38ULL * df3;

    d3_19  = 19ULL * fd3;
    d4_38  = 38ULL * fd4;

   
    p0 = fd0 * fd0 + d1_38 * fd4  + d2_38 * fd3;
    p1 = d0_2 * fd1 + d2_38 * fd4 + d3_19 * fd3;
    p2 = d0_2 * fd2 + fd1 * fd1   + d3_38 * fd4;
    p3 = d0_2 * fd3 + d1_2 * fd2  + d4_38 * fd4;
    p4 = d0_2 * fd4 + d1_2 * fd3  + fd2 * fd2;

    
    result0    = ((uint64_t) p0) & mask;
    carry      = (uint64_t) (p0 >> 51);
    p1        += carry;
    result1    = ((uint64_t) p1) & mask;
    carry      = (uint64_t) (p1 >> 51);
    p2        += carry;
    result2    = ((uint64_t) p2) & mask;
    carry      = (uint64_t) (p2 >> 51);
    p3        += carry;
    result3    = ((uint64_t) p3) & mask;
    carry      = (uint64_t) (p3 >> 51);
    p4        += carry;
    result4    = ((uint64_t) p4) & mask;
    carry      = (uint64_t) (p4 >> 51);
    result0   += 19ULL * carry;
    carry      = result0 >> 51;
    result0   &= mask;
    result1   += carry;
    carry      = result1 >> 51;
    result1   &= mask;
    result2   += carry;

 
    h[0] = result0;
    h[1] = result1;
    h[2] = result2;
    h[3] = result3;
    h[4] = result4;
}