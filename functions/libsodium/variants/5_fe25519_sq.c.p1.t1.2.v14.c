void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], ff[5], ff_mult[5], ff_double[2];
    uint64_t hr[5], carry;

    for (int i = 0; i<5; i++)
      ff[i] = (uint128_t) f[i];

    ff_double[0] = ff[0] << 1;
    ff_double[1] = ff[1] << 1;
    
    ff_mult[0] = 38ULL * ff[1];
    ff_mult[1] = 38ULL * ff[2];
    ff_mult[2] = 38ULL * ff[3];
    ff_mult[3] = 19ULL * ff[3];
    ff_mult[4] = 19ULL * ff[4];

    r[0] = ff[0]*ff[0] + ff_mult[0]*ff[4] + ff_mult[1]*ff[3];
    r[1] = ff_double[0]*ff[1] + ff_mult[1]*ff[4] + ff_mult[3]*ff[3];
    r[2] = ff_double[0]*ff[2] + ff[1]*ff[1] + ff_mult[2]*ff[4];
    r[3] = ff_double[0]*ff[3] + ff_double[1]*ff[2] + ff_mult[4]*ff[4];
    r[4] = ff_double[0]*ff[4] + ff_double[1]*ff[3] + ff[2]*ff[2];

    for(int i=0; i<5; i++) {
        hr[i] = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        r[i+1] += carry;
        carry  = hr[i] >> 51;
        hr[i] &= mask;
        hr[i+1] += carry;
    }

    h[0] = hr[0];
    h[1] = hr[1];
    h[2] = hr[2];
    h[3] = hr[3];
    h[4] = hr[4];
}