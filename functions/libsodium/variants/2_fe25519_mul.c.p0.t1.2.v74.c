fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_cpy[5], g_cpy[5];
    uint64_t carry, fd;

    for (int i = 0; i<5; i++){
        f_cpy[i] = (uint128_t) f[i];
        g_cpy[i] = (uint128_t) g[i];
    }

    for (int i = 1; i<5; i++){
        f_cpy[i] = 19ULL * f_cpy[i];
    }
    r[0] = f_cpy[0] * g_cpy[0] + f_cpy[1] * g_cpy[4] + f_cpy[2] * g_cpy[3] + f_cpy[3] * g_cpy[2] + f_cpy[4] * g_cpy[1];
    for (int i = 1; i<5; i++){
        f_cpy[i] = (uint128_t) f[i];
        fd = f_cpy[0] * g_cpy[i];
        for (int j = 1; j<5; j++){
            fd += f_cpy[j] * g_cpy[(i+j)%5];
        }
        r[i] = fd;
    }

    for (int i = 0; i<5; i++){
        h[i]    = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        r[(i+1)%5] += carry;
    }
    for (int i = 0; i<5; i++){
        carry  = h[i] >> 51;
        h[i]   &= mask;
        h[(i+1)%5] += carry;
    }
}