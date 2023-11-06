fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{   
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], fnc[5], fac[5], gfc[5];
    uint128_t f119, f219, f319, f419;
    uint64_t  rir[5];
    uint64_t  carry;

    for(int i = 0; i < 5; i++){
        fnc[i] = (uint128_t) f[i];
        gfc[i] = (uint128_t) g[i];
    }

    f119 = 19ULL * fnc[1];
    f219 = 19ULL * fnc[2];
    f319 = 19ULL * fnc[3];
    f419 = 19ULL * fnc[4];

    r[0] = fnc[0] * gfc[0] + f119 * gfc[4] + f219 * gfc[3] + f319 * gfc[2] + f419 * gfc[1];
    r[1] = fnc[0] * gfc[1] + fnc[1] * gfc[0] + f219 * gfc[4] + f319 * gfc[3] + f419 * gfc[2];
    r[2] = fnc[0] * gfc[2] + fnc[1] * gfc[1] + fnc[2] * gfc[0] + f319 * gfc[4] + f419 * gfc[3];
    r[3] = fnc[0] * gfc[3] + fnc[1] * gfc[2] + fnc[2] * gfc[1] + fnc[3] * gfc[0] + f419 * gfc[4];
    r[4] = fnc[0] * gfc[4] + fnc[1] * gfc[3] + fnc[2] * gfc[2] + fnc[3] * gfc[1] + fnc[4] * gfc[0];

    for(int i = 0; i < 5; i++){
        rir[i] = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        r[i+1] += carry;
    }

    rir[0] += 19ULL * carry;
    carry  = rir[0] >> 51;
    rir[0] &= mask;
    rir[1] += carry;
    carry  = rir[1] >> 51;
    rir[1] &= mask;
    rir[2] += carry;

    for(int i = 0; i<5; i++){
        h[i] = rir[i];  
    }
}