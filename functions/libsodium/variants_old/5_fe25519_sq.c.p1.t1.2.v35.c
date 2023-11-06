void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_new[5], f1_2, f_2[3], f_19[2], f2, f3;
    uint64_t _carry, r1[5];
    for(int i = 0; i < 5; ++i) {
      f_new[i] = (uint128_t) f[i];
    }

    f1_2 = f_new[0] << 1;
    f3 = f_new[1] << 1;

    for(int i = 1; i < 4; ++i) {
      f_2[i-1] = 38ULL * f_new[i];
    }

    for(int i = 3; i < 5; ++i) {
      f_19[i-3] = 19ULL * f_new[i];
    }

    r[0] =   f_new[0] * f_new[0] + 38ULL * f_new[1] * f_new[4] + f_2[1] * f_new[2];
    r[1] = f1_2 * f_new[1] + f_2[1] * f_new[3] + f_19[0] * f_new[2];
    r[2] = f1_2 * f_new[1] + f_new[1] * f_new[1] + f_2[2] * f_new[3];
    r[3] = f1_2 * f_new[2] + f3 * f_new[1] + f_19[1] * f_new[3];
    r[4] = f1_2 * f_new[3] + f3 * f_new[2] + f_new[1] * f_new[1];

    _carry = 0;
    for(int i = 0; i < 5; ++i) {
        r1[i] = (r[i] + _carry) & mask;
        _carry = (uint64_t) (r[i] + _carry >> 51);
        r1[i] = r1[i] & mask;
        _carry = (uint64_t) (r1[i] >> 51);
        r1[i] = (r1[i] + 19ULL * _carry) & mask;
        _carry = (uint64_t) (r1[i] >> 51);
    }

    for(int i = 0; i < 5; ++i) {
        h[i] = r1[i];
    }
}