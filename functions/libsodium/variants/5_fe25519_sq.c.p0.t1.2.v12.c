fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t u0, u1, u2, u3, u4;
    uint128_t v0, v1, v2, v3, v4;
    uint128_t v0_2, v1_2, v1_38, v2_38, v3_38, v3_19, v4_19;
    uint64_t  u00, u01, u02, u03, u04;
    uint64_t  overflow;

    v0 = (uint128_t) f[0];
    v1 = (uint128_t) f[1];
    v2 = (uint128_t) f[2];
    v3 = (uint128_t) f[3];
    v4 = (uint128_t) f[4];

    v0_2 = v0 << 1;
    v1_2 = v1 << 1;

    v1_38 = 38ULL * v1;
    v2_38 = 38ULL * v2;
    v3_38 = 38ULL * v3;

    v3_19 = 19ULL * v3;
    v4_19 = 19ULL * v4;

    u0 =   v0 * v0 + v1_38 * v4 + v2_38 * v3;
    u1 = v0_2 * v1 + v2_38 * v4 + v3_19 * v3;
    u2 = v0_2 * v2 +    v1 * v1 + v3_38 * v4;
    u3 = v0_2 * v3 +  v1_2 * v2 + v4_19 * v4;
    u4 = v0_2 * v4 +  v1_2 * v3 +    v2 * v2;

    u00     = ((uint64_t) u0) & mask;
    overflow = (uint64_t) (u0 >> 51);
    u1     += overflow;
    u01     = ((uint64_t) u1) & mask;
    overflow = (uint64_t) (u1 >> 51);
    u2     += overflow;
    u02     = ((uint64_t) u2) & mask;
    overflow = (uint64_t) (u2 >> 51);
    u3     += overflow;
    u03     = ((uint64_t) u3) & mask;
    overflow = (uint64_t) (u3 >> 51);
    u4     += overflow;
    u04     = ((uint64_t) u4) & mask;
    overflow = (uint64_t) (u4 >> 51);

    h[0] = u00;
    h[1] = u01;
    h[2] = u02;
    h[3] = u03;
    h[4] = u04;
}
