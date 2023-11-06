Here is a program variant of the given function. The rearranges the multiplications slightly to break apart what are effectively equivalent computations in each line more explicitly:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f1_2_2, f3_2_2, f1_2, f2_2, f3_2, f4_2;


    f1_2 = f[1] * 2ULL;
    f2_2 = f[2] * 2ULL;
    f1_2_2 = f1_2 * 2ULL;
    f3_2_2 = f[4] * 2ULL;
    f3_2 = f[4] * 2ULL;
    f4_2 = f[5] * 2ULL;


    r[0] = ((uint128_t) f[0] * g[0] + 
            ((uint128_t)f1_2_2 * g[5] +
             (uint128_t)f3_2_2 * g[4]  +
             (uint128_t)f[3] * f3_2 * g[3]) +  
            ((uint128_t) f[4] * f4_2 * g[2] +
             (uint128_t) f[2] * f2_2 * g[1]));

    h[0] = r[0] & mask;
    carry = r[0] >> 51;
    r[1] += carry;


    r[1] = (f[0] * g[1] +   
            f1_2 * g[0] +
            f3_2 * g[4] +
            (uint128_t) f[4] * f3_2 * g[3]) + 
           (f[3] * g[2] +
           (uint128_t)f[2] * f1_2_2 * g[1];

    h[1] = r[1] & mask;
    carry = r[1] >> 51;
    r[2] += carry;

    r[03] = (f[0] * g[3] +
            f1_2 * g[2] +
            f3_2 * g[1] +  
            f1_2 * g[4] +
            (uint128_t)f[4] * f2_2 * g[0];;

    h[2] = r[2] & mask;
    carry = r[2] >> 51;
    r[3] += carry;

    r[4] = (f01 * g[4] +
            g01 * g[3] +
            g02 * g[2]+
            g1L2 * g[1] +
            g02 * g[0]);

    h[3] = r[3] & mask;
    carry = r[3] >> 51;
    r[4] += carry;
   

    h[4] = r[4] & mask;
}


This program leaves the `carry` operation to updating the `r[x]` variables rather than introducing extraneous variables. It continues to compute the intended sums of multiplication, but it splits off each term as determinant to aid in simplifying the calculations.