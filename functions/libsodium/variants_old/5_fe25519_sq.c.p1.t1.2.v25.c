void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f_elems[5];
    uint128_t temp_vals[7];
    int i;

    for(i = 0; i < 5; i++) {
        f_elems[i] = (uint128_t) f[i];
    }     

    temp_vals[0] = f_elems[0] << 1;
    temp_vals[1] = f_elems[1] << 1;

    temp_vals[2] = 38ULL * f_elems[1];
    temp_vals[3] = 38ULL * f_elems[2];
    temp_vals[4] = 38ULL * f_elems[3];

    temp_vals[5] = 19ULL * f_elems[3];
    temp_vals[6] = 19ULL * f_elems[4];

    r[0] =   f_elems[0] * f_elems[0] + temp_vals[2] * f_elems[4] + temp_vals[3] * f_elems[3];
    r[1] = temp_vals[0] * f_elems[1] + temp_vals[3] * f_elems[4] + temp_vals[5] * f_elems[3];
    r[2] = temp_vals[0] * f_elems[2] +    f_elems[1] * f_elems[1] + temp_vals[4] * f_elems[4];
    r[3] = temp_vals[0] * f_elems[3] +  temp_vals[1] * f_elems[2] + temp_vals[6] * f_elems[4];
    r[4] = temp_vals[0] * f_elems[4] +  temp_vals[1] * f_elems[3] +    f_elems[2] * f_elems[2];

    uint64_t carry;
    for (i = 0; i < 5; i++) {
        r[i] = ((uint64_t) r[i] < mask) ? r[i] : (r[i+1] += (uint64_t) (r[i] >> 51), ((uint64_t) r[i]) & mask);
    }
    r[0] += 19ULL * ((uint64_t) (r[4] >> 51));
    for (i = 0; i < 4; i++) {
        r[i] = ((uint64_t) r[i] < mask) ? r[i] : (r[i+1] += r[i] >> 51, ((uint64_t) r[i]) & mask);
    }
    
    for(i = 0; i < 5; i++) {
        h[i] = r[i];
    }
}