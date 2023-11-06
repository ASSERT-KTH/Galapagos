fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], i[5];
    uint64_t r_mod[5], carry;
    uint128_t f_mul;

    for (uint8_t j = 0; j < 5; j++) {
        i[j] = (uint128_t) f[j];
    }

    f_mul = i[0] << 1;

    r[0] = i[0] * i[0] + 38ULL * i[1] * i[4] + 38ULL * i[2] * i[3];
    r[1] = f_mul * i[1] + 38ULL * i[2] * i[4] + 19ULL * i[3] * i[3];
    r[2] = f_mul * i[2] + i[1] * i[1] + 38ULL * i[3] * i[4];
    r[3] = f_mul * i[3] + (i[1] << 1) * i[2] + 19ULL * i[4] * i[4];
    r[4] = f_mul * i[4] + (i[1] << 1) * i[3] + i[2] * i[2];

    for(uint8_t j = 0; j < 5; j++) {
        r_mod[j] = r[j] & mask;
        carry = r[j] >> 51;
        if (j < 4) {
            r[j + 1] += carry;
        }
    }

    r_mod[0] += 19ULL * carry;
    carry = r_mod[0] >> 51;
    r_mod[0] &= mask;
    r_mod[1] += carry;c
    carry = r_mod[1] >> 51;
    r_mod[1] &= mask;
    r_mod[2] += carry;

    for (uint8_t j = 0; j < 5; j++) {
        h[j] = r_mod[j];
    }
}