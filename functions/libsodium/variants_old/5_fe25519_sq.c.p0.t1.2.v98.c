fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f_f[5];
    uint128_t tp0, tp1, tp2, tp3, tp4;
    uint64_t  cur, carry;

    for(int i=0; i<5; i++) f_f[i] = f[i];

    tp0 = f_f[0] << 1;
    tp1 = f_f[1] << 1;

    tp2 = 38ULL * f_f[1];
    tp3 = 38ULL * f_f[2];
    tp4 = 38ULL * f_f[3];

    tp0 = 19ULL * f_f[3];
    tp1 = 19ULL * f_f[4];

    r[0] =   f_f[0] * f_f[0] + tp2 * f_f[4] + tp3 * f_f[3];
    r[1] = tp0 * f_f[1] + tp3 * f_f[4] + tp0 * f_f[3];
    r[2] = tp0 * f_f[2] +    f_f[1] * f_f[1] + tp4 * f_f[4];
    r[3] = tp0 * f_f[3] +  tp1 * f_f[2] + tp1 * f_f[4];
    r[4] = tp0 * f_f[4] +  tp1 * f_f[3] +    f_f[2] * f_f[2];

    cur    = ((uint64_t) r[0]) & mask;
    carry  = (uint64_t) (r[0] >> 51);
    r[1]  += carry;
    r[0]    = cur & mask;
    
    cur     = ((uint64_t) r[1]) & mask;
    carry  = (uint64_t) (r[1] >> 51);
    r[2]  += carry;
    r[1]    = cur & mask;

    cur     = ((uint64_t) r[2]) & mask;
    carry  = (uint64_t) (r[2] >> 51);
    r[3]  += carry;
    r[2]    = cur & mask;

    cur     = ((uint64_t) r[3]) & mask;
    carry  = (uint64_t) (r[3] >> 51);
    r[4]  += carry;
    r[3]    = cur & mask;

    cur    = ((uint64_t) r[4]) & mask;
    carry = (uint64_t) (r[4] >> 51);
    r[0] += 19ULL * carry;
    r[4]    = cur & mask;
    
    carry  = r[0] >> 51;
    r[0]  &= mask;
    r[1]  += carry;

    carry  = r[1] >> 51;
    r[1]  &= mask;
    r[2]  += carry;

    for(int i=0; i<5; i++) h[i] = r[i];
}