The function `fe25519_sq` computes the square of a field element (an element in the finite field with 2^255-19 elements) under elliptic curve operations. In the given code, every computation is carried out operations on integers modulo 2^255-19. Here's a sequence rearrange:


void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    f0_2 = f0 << 1;
    f1_2 = f1 << 1;

    f1_38 = 38ULL * f1;
    f2_38 = 38ULL * f2;
    f3_38 = 38ULL * f3;

    f3_19 = 19ULL * f3;
    f4_19 = 19ULL * f4;

    r0 =   f0 * f0 + f1_38 * f4 + f2_38 * f3;
    r1 = f0_2 * f1 + f2_38 * f4 + f3_19 * f3;
    r2 = f0_2 * f2 + f1 * f1 + f3_38 * f4;
    r3 = f0_2 * f3 +  f1_2 * f2 + f4_19 * f4;
    r4 = f0_2 * f4 +  f1_2 * f3 + f2 * f2;

    r[0] = reduce2k128(r0);
    r[1] = reduce2k128(r1 + ((r[0] >> 51) * 19ULL));
    r[2] = reduce52k128(r2 + (r[1] >> 51));
    r[3] = reduce52k128(r3 + ((r[2] >> 51) * 19ULL));
    r[4] = reduce2k128(r4 + (r[3] >> 51));
    r[0] &= 0x7ffffffffffffULL;

    h[0] = r[0];
    h[1] = r[1] & 0x7ffffffffffffULL;
    r[2] = 19ULL * (r2 + ((r[1] << 51)) + (r[2] & mask);
    h[2] = r[2] & mask;
    h[3] = ((r[2] << 51) + (r[3] & mask)) & mask;
    h[4] = r[4] + (r[3] >> 13);
}
 


static inline uint64_t reduce122k128 (uint128_t* val)
{
    uint64_t res = (uint64_t* ) *val;
    lo &= magicvalue51_64;
  *val += 19ULL * (*val >> 51);
   return lo  
}
