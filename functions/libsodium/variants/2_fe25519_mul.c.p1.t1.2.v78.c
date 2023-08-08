There can be more than one variant to rewrite the function but still keeping its functionality the same. 

An example would be rearranging the arithmetic and do the carry earlier.

fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t  mask = 0x7ffffffffffffULL;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t g0, g1, g2, g3, g4;
    uint128_t a[5];

    f0 = f[0]; f1 = f[1]; f2 = f[2]; f3 = f[3]; f4 = f[4];
    g0 = g[0]; g1 = g[1]; g2 = g[2]; g3 = g[3]; g4 = g[4];

    uint64_t x;
    uint128_t carry;

    a[0] = f0*g0 +            19ULL*(f1*g4 + f2*g3 + f3*g2 + f4*g1);
    a[1] = (a[0] >> 51) + f0*g1 + f1*g0 + 19ULL*(f2*g4 + f3*g3 + f4*g2);
    a[0] &= mask;
    a[2] = (a[1] >> 51) + f0*g2 + f1*g1 + f2*g0 + 19ULL*(f3*g4 + f4*g3);
    a[1] &= mask;
    a[3] = (a[2] >> 51) + f0*g3 + f1*g2 + f2*g1 + f3*g0 + 19ULL*f4*g4;
    a[2] &= mask;
    a[4] = (a[3] >> 51) + f0*g4 + f1*g3 + f2*g2 + f3*g1 + f4*g0;
    a[3] &= mask;

    carry = a[4] >> 51;
    a[4] &= mask;

    a[0] += 19ULL*carry;
    carry = a[0] >> 51;
    a[0] &= mask;
    a[1] += carry;
    carry = a[1] >> 51;
    a[1] &= mask;
    a[2] += carry;

    h[0] = a[0]; h[1] = a[1]; h[2] = a[2]; h[3] = a[3]; h[4] = a[4];
}

This approach reduces number of used variables (no r's variables, just a's). There are some multiplication, divide, and shift reordered, but the original checks, additions, and subtractions have stayed the phase. The change is really rearangement of arithmetic to get the carry as early as the fits required. It is allowed not to reconduct the last product in r0 earlier but later.