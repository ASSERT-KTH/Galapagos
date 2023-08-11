Sure, one possible way of making this modification would be to mechanically "unroll" each of the datapath steps. This results in elimination of temporal local variables ('r0' through 'r4', and 'carry') yielding individual code lines appearing sequential but they doesn't implore sequential execution as these are independent computations which can be reordered or executed in parallel. To facilitate readability, parentheses were employed.

Here's the modified version:


void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f0, f1, f2, f3, f4;
    
    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    uint64_t carry;
    
    h[0] = (((f0*f0 + (38*f1*f4) + (38*f2*f3))) & mask);
    carry = (h[0] >> 51);
    h[1] = (h[0] + ((2*f0*f1) + ((38*f2*f4) + (19*f3*f3))) + carry) & mask;
    carry = (h[1] >> 51);
    h[2] = (h[1] + (2*f0*f2 + (f1*f1) + 38*f3*f4) + carry) & mask;
    carry = (h[2] >> 51);
    h[3] = (h[2] + ((2*f0*f3) + (2*f1*f2) + (19*f4*f4)) + carry) & mask;
    carry = (h[3] >> 51);
    h[4] = (h[3] + (2*f0*f4 + (2*f1*f3) + (f2*f2)) + carry) & mask;
    
    carry = (h[4] >> 51);
    h[0] += 19*carry;
    carry = (h[0] >> 51);
    h[0] &= mask;
   
    h[1] += carry;
    carry = (h[1] >> 51);
    h[1] &= mask;
    
    h[2] += carry;
}
