fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t findmask = 0x7ffffffffffffULL;
    uint128_t res0, res1, res2, res3, res4;
    uint128_t fore0, fore1, fore2, fore3, fore4;
    uint128_t two_f0s, two_f1s, multiple38_f1, multiple38_f2, multiple38_f3, multiple19_f3, multiple19_f4;
    uint64_t  res00, res01, res02, res03, res04;
    uint64_t  transport;

    fore0 = (uint128_t) f[0];
    fore1 = (uint128_t) f[1];
    fore2 = (uint128_t) f[2];
    fore3 = (uint128_t) f[3];
    fore4 = (uint128_t) f[4];

    two_f0s = fore0 * 2;
    two_f1s = fore1 * 2;

    multiple38_f1 = 38ULL * fore1;
    multiple38_f2 = 38ULL * fore2;
    multiple38_f3 = 38ULL * fore3;

    multiple19_f3 = 19ULL * fore3;
    multiple19_f4 = 19ULL * fore4;

    res0 =   fore0 * fore0 + multiple38_f1 *fore4 + multiple38_f2 * fore3;
    res1 = two_f0s * fore1 + multiple38_f2 * fore4 + multiple19_f3 * fore3;
    res2 = two_f0s * fore2 +   fore1 * fore1 + multiple38_f3 * fore4;
    res3 = two_f0s * fore3 + two_f1s * fore2 + multiple19_f4 * fore4;
    res4 = two_f0s * fore4 + two_f1s * fore3 +   fore2 * fore2;

    res00    = ((uint64_t) res0) & findmask;
    transport  = (uint64_t) (res0 >> 51);
    res1    += transport;
    res01    = ((uint64_t) res1) & findmask;
    transport  = (uint64_t) (res1 >> 51);
    res2    += transport;
    res02    = ((uint64_t) res2) & findmask;
    transport  = (uint64_t) (res2 >> 51);
    res3    += transport;
    res03    = ((uint64_t) res3) & findmask;
    transport  = (uint64_t) (res3 >> 51);
    res4    += transport;
    res04    = ((uint64_t) res4) & findmask;
    transport  = (uint64_t) (res4 >> 51);
    res00   += 19ULL * transport;
    transport  = res00 >> 51;
    res00   &= findmask;
    res01   += transport;
    transport  = res01 >> 51;
    res01   &= findmask;
    res02   += transport;

    h[0] = res00;
    h[1] = res01;
    h[2] = res02;
    h[3] = res03;
    h[4] = res04;
}