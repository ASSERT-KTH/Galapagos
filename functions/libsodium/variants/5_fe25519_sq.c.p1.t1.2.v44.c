void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_elements[5], multiples[5];
    uint64_t carry, r_elements[5];

    f_elements[0] = (uint128_t) f[0];
    f_elements[1] = (uint128_t) f[1];
    f_elements[2] = (uint128_t) f[2];
    f_elements[3] = (uint128_t) f[3];
    f_elements[4] = (uint128_t) f[4];

    multiples[0] = f_elements[0] << 1;
    multiples[1] = f_elements[1] << 1;

    multiples[2] = 38ULL * f_elements[1];
    multiples[3] = 38ULL * f_elements[2];
    multiples[4] = 38ULL * f_elements[3];

    multiples[1] = 19ULL * f_elements[3];
    multiples[2] = 19ULL * f_elements[4];

    r[0] =   f_elements[0] * f_elements[0] + multiples[2] * multiples[1] + multiples[3] * multiples[0];
    r[1] = multiples[3] * f_elements[0] + multiples[3] * multiples[1] + multiples[1] * multiples[0];
    r[2] = multiples[0] * f_elements[1] +    f_elements[1] * f_elements[1] + multiples[4] * multiples[2];
    r[3] = multiples[0] * f_elements[2] +  multiples[1] * f_elements[1] + multiples[2] * multiples[2];
    r[4] = multiples[0] * multiples[2] +  multiples[1] * f_elements[2] +    f_elements[1] * f_elements[1];

    for(int i = 0; i < 5; ++i){
        r_elements[i] = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        r[i+1] += carry;
    }

    r_elements[0] += 19ULL * carry;
    carry = r_elements[0] >> 51;
    r_elements[0] &= mask;
    r_elements[1] += carry;
    carry = r_elements[1] >> 51;
    r_elements[1] &= mask;
    r_elements[2] += carry;

    for(int i = 0; i < 5; ++i){
        h[i] = r_elements[i];
    }
}