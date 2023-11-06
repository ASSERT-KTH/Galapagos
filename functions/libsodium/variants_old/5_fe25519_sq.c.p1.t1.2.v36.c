
void fe25519_sq(fe25519 h, const fe25519 f)
{
    uint64_t mask = ~(0xFFFFFFFFFFFF8000ULL);
    uint128_t r[5], fval[5], tmp;
    uint64_t carry, result[5];

    for(int i = 0; i < 5; i++)
    {
        fval[i] = (uint128_t) f[i];
    }
    fval[1] = fval[1] << 1;
    fval[2] = fval[2] << 1; 

    r[0] =   fval[0]**2 + (38ULL * fval[1]) * fval[4] + (38ULL * fval[2]) * fval[3];
    r[1] = fval[0] * fval[1] + fval[2] * (38ULL * fval[4]) + (19ULL * fval[3]**2);
    r[2] = fval[0] * fval[2] + fval[1]**2 + (38ULL * fval[3] * fval[4]);
    r[3] = fval[0] * fval[3] + fval[1] * fval[2] + (19ULL * (fval[4]**2));
    r[4] = fval[0] * fval[4] + fval[1] * fval[3] + fval[2]**2;

    for(int i = 0; i < 5; i++) {
        result[i] = r[i] & mask;
        tmp = r[i] >> 51;
        if (i+1 < 5) {
            r[i+1] += tmp; 
        } else {
            result[0] += 19ULL * tmp;
            result[1] += result[0] >> 51;
            result[0] = result[0] & mask;
        }
    }
    result[1] = result[1] & mask;
    result[2] += result[1] >> 51;

    for(int i = 0; i < 5; i++)
    {
        h[i] = result[i];
    }
}
