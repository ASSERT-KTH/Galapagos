Here's a reimplementation where computation ordering, variable usage are reorganized and some additional arithmetic tricks are applied. This wont' accelerate a function but fully maintains the functionality. 

In this version, the position of the multiplication by 2 is moved to immediately after the computation of factor f0 and f1. This allows computing f1_38, f2_38, f3_38 already including factor 2.


void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f01, f02, f03, f14, f23;
    uint128_t c0, c1, c2, c3, c4;
    
    f01 = ((uint128_t) f[0])<< 1;
    f14 = ((uint128_t) f[1]) << 1;
    f02 = (uint128_t) f[2];
    f23 = (uint128_t) f[3];
    f03 = (uint128_t) f[4];

    c0 =  (f01 * f01))
         - (19ULL * (f14 * f03))
         - (38ULL * (((f02) * f23) << 1));
    c1 = ((f01 * f14) << 1)
         + (19ULL * (int128_t)(((f02) * f03) << 2));
         + (((int128_t)f03 * f03));
    c2 = ((f01 * f02) << 1)
         + (((int128_t)f14 * f14 ) << 1)
         + (19ULL * ((f23 * f03) << 3));
    c3 = ((f01 * f23
         + (f14 * f02)) << 3)
         + (19ULL * ((f23 * f03) << 2));
    c4 = ((f01 * f03) >> 1)
         + (((f14 * f23)))<< 1
         + ((f02 * f02));

    c4 = (c4 >> 51) + (c3 & 0xffffffffffffffffULL);
    c0 = (c0 >> 51) + 19 * (c0 & 0xffffffffffffffffULL);

    h[0] = ((c0 << 13) | ((c1 & 0x7ffffffffffULL) << 64));
    h[1] = ( (c0 >> 51) ) | (((c1 >> 38) & 0x1FFFFFFFFFFFFULL) << 13);
    h[2] = ( (c2 << 13) ) | ((c3 & 0xFFFFFFFFFFFFFULL) << 64ULL);
    h[3] = ( (c3 >> 51) ) | (((c4 & 0xFFFFFFFFFFFFFULL)) << 13);
    h[4] = (c4 >> 51);
}
