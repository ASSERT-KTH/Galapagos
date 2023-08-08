fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t modMask = 0x7ffffffffffffULL;
    uint64_t r[5];
    uint128_t t[5];
    uint128_t c1, c2, c3, c4, c5;
    uint64_t c, o;

    void to_uint128_t(const fe25519 in, uint128_t out[5]) {
        for(int i=0;i<5;++i) {
            out[i] = (uint128_t) in[i];
        }
    }

    to_uint128_t(f, t);
    c1 = 19ULL * t[1];
    c2 = 19ULL * t[2];
    c3 = 19ULL * t[3];
    c4 = 19ULL * t[4];

    r[0] = t[0] * g[0] + c1 * g[4] + c2 * g[3] + c3 * g[2] + c4 * g[1];
    r[1] = t[0] * g[1] + t[1] * g[0] + c2 * g[4] + c3 * g[3] + c4 * g[2];
    r[2] = t[0] * g[2] + t[1] * g[1] + t[2] * g[0] + c3 * g[4] + c4 * g[3];
    r[3] = t[0] * g[3] + t[1] * g[2] + t[2] * g[1] + t[3] * g[0] + c4 * g[4];
    r[4] = t[0] * g[4] + t[1] * g[3] + t[2] * g[2] + t[3] * g[1] + t[4] * g[0];

    o    = ((uint64_t) r[0]) & modMask;
    c  = (uint64_t) (r[0] >> 51);
    r[1]    += c;
    o    = ((uint64_t) r[1]) & modMask;
    c  = (uint64_t) (r[1] >> 51);
    r[2]    += c;
    o    = ((uint64_t) r[2]) & modMask;
    c  = (uint64_t) (r[2] >> 51);
    r[3]    += c;
    o    = ((uint64_t) r[3]) & modMask;
    c  = (uint64_t) (r[3] >> 51);
    r[4]    += c;
    o    = ((uint64_t) r[4]) & modMask;
    c  = (uint64_t) (r[4] >> 51);
    r[0]   += 19ULL * c;
    c  = r[0] >> 51;
    r[0]   &= modMask;
    r[1]   += c;
    c  = r[1] >> 51;
    r[1]   &= modMask;
    r[2]   += c;

    h[0] = r[0];
    h[1] = r[1];
    h[2] = r[2];
    h[3] = r[3];
    h[4] = r[4];
}