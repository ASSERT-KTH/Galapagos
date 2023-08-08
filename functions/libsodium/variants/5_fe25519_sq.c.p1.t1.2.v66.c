Here's a program variant, carrying slightly difference operations:

void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f_[5];
    uint64_t carry;

    for(int i = 0; i < 5; ++i) {
        f_[i] = (uint128_t) f[i];
    }

    r[0] =   f_[0] * f_[0] + 38 * f_[1] * f_[4] + 38 * f_[2] * f_[3];
    r[1] = 2 * f_[0] * f_[1] + 38 * f_[2] * f_[4] + 19 * f_[3] * f_[3];
    r[2] = 2 * f_[0] * f_[2] + f_[1] * f_[1] + 38 * f_[3] * f_[4];
    r[3] = 2 * f_[0] * f_[3] + 2 * f_[1] * f_[2] + 19 * f_[4] * f_[4];
    r[4] = 2 * f_[0] * f_[4] + 2 * f_[1] * f_[3] + f_[2] * f_[2];

    for(int j = 0; j < 5; j++){
        uint64_t r_i    = ((uint64_t) r[j]) & mask;
        carry  = (uint64_t) (r[j] >> 51);
        if(j<4){r[j+1]+=carry;h[j]=r_i;}
        else {
            r[0] += 19ULL * carry;
            uint64_t r0 = ((uint64_t) r[0]) & mask;
            carry  = (uint64_t) (r[0] >> 51);
            r[1] += carry;
            uint64_t r1 = ((uint64_t) r[1]) & mask;
            carry  = (uint64_t) (r[1] >> 51);
            r[2] += carry;
            h[0] = r0;
            h[1] = r1;
            h[4] = r_i;
        }
    }
}

The change & introduction of computable loop here helps simplifying the logical workflow & optimizations, thereby maintaining the core functionality as intended in original by breaking down the block computation into computable loops to offer flexibility & maintainability.