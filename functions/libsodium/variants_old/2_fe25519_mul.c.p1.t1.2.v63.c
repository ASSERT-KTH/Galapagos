
fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f0[5], g0[5];
    uint128_t f1_19, f2_19, f3_19, f4_19;
    uint64_t  h_val[5];
    uint64_t  carry;
    int i;

    for(i = 0; i < 5; ++i){
      f0[i] = (uint128_t) f[i];
      g0[i] = (uint128_t) g[i];
    }

    f1_19 = 19ULL * f0[1];
    f2_19 = 19ULL * f0[2];
    f3_19 = 19ULL * f0[3];
    f4_19 = 19ULL * f0[4];

    r[0] = f0[0]*g0[0] + f1_19*g0[4] + f2_19*g0[3] + f3_19*g0[2] + f4_19*g0[1];
    r[1] = f0[0]*g0[1] + f0[1]*g0[0] + f2_19*g0[4] + f3_19*g0[3] + f4_19*g0[2];
    r[2] = f0[0]*g0[2] + f0[1]*g0[1] + f0[2]*g0[0] + f3_19*g0[4] + f4_19*g0[3];
    r[3] = f0[0]*g0[3] + f0[1]*g0[2] + f0[2]*g0[1] + f0[3]*g0[0] + f4_19*g0[4];
    r[4] = f0[0]*g0[4] + f0[1]*g0[3] + f0[2]*g0[2] + f0[3]*g0[1] + f0[4]*g0[0];

    for(i = 0; i < 4; ++i){
        h_val[i] = ((uint64_t) r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);
        r[i+1] += carry;
    }
    h_val[4] = ((uint64_t) r[4]) & mask;
    carry = (uint64_t) (r[4] >> 51);
    h_val[0] += 19ULL * carry;
    carry = h_val[0] >> 51;
    h_val[0] &= mask;
    h_val[1] += carry;
    carry = h_val[1] >> 51;
    h_val[1] &= mask;
    h_val[2] += carry;

    for(i = 0; i < 5; ++i){
      h[i] = h_val[i];
    }
}
This variant combines the scalar values into arrays for consistency and simplified reading.
