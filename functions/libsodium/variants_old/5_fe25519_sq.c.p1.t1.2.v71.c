
fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_[5], f_times[5];
    uint64_t  h_[5];
    uint64_t  carry;

    for (int i = 0; i < 5; ++i) {
        f_[i] = (uint128_t)f[i];   
    }

    f_times[0] = f_[0] << 1;
    f_times[1] = f_[1] << 1;

    f_times[2] = 38ULL * f_[1];
    f_times[3] = 38ULL * f_[2];
    f_times[4] = 38ULL * f_[3];

    f_times[5] = 19ULL * f_[3];
    f_times[6] = 19ULL * f_[4];

    r[0] = f_[0] * f_[0] + f_times[2] * f_[4] + f_times[3] * f_[3];
    r[1] = f_times[0] * f_[1] + f_times[2] * f_[4] + f_times[5] * f_[3];
    r[2] = f_times[0] * f_[2] + f_[1] * f_[1] + f_times[4] * f_[4];
    r[3] = f_times[0] * f_[3] + f_times[1] * f_[2] + f_times[6] * f_[4];
    r[4] = f_times[0] * f_[4] + f_times[1] * f_[3] + f_[1] * f_[1];

    for(int i =0; i< 5;++i){
    h_[i]     = ((uint64_t) r[i]) & mask;
    carry     = (uint64_t) (r[i] >> 51);
    if (i != 4) r[i+1] += carry;
    }

    h_[0]     += 19ULL * carry;
    carry     = h_[0] >> 51;
    h_[0]     &= mask;
    h_[1]     += carry;
    carry     = h_[1] >> 51;
    h_[1]     &= mask;
    h_[2]     += carry;

    for (int i = 0; i < 5; ++i) {
        h[i]     = h_[i];
    }
}
