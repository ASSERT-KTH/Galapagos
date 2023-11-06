Here is variant of the above code which maintains its original functionality:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f_[5];
    uint128_t g_[5];
    uint64_t carry;
    uint64_t h_[5];

    for (int i=0; i<5; i++){
        f_[i] = (uint128_t) f[i];
        g_[i] = (uint128_t) g[i];
    }

    uint128_t f1_19 = 19ULL * f_[1];
    uint128_t f2_19 = 19ULL * f_[2];
    uint128_t f3_19 = 19ULL * f_[3];
    uint128_t f4_19 = 19ULL * f_[4];

    r[0] = f_[0] * g_[0] + f1_19 * g_[4] + f2_19 * g_[3] + f3_19 * g_[2] + f4_19 * g_[1];
    r[1] = f_[0] * g_[1] + f_[1] * g_[0] + f2_19 * g_[4] + f3_19 * g_[3] + f4_19 * g_[2];
    r[2] = f_[0] * g_[2] + f_[1] * g_[1] + f_[2] * g_[0] + f3_19 * g_[4] + f4_19 * g_[3];
    r[3] = f_[0] * g_[3] + f_[1] * g_[2] + f_[2] * g_[1] + f_[3] * g_[0] + f4_19 * g_[4];
    r[4] = f_[0] * g_[4] + f_[1] * g_[3] + f_[2] * g_[2] + f_[3] * g_[1] + f_[4] * g_[0];

    for(int i = 0; i<5; i++){
        h_[i] = ((uint64_t) r[i]) & mask;
	carry  = (uint64_t) (r[i] >> 51);
	i==4 ? r[0] += carry : r[i+1] += carry;
    }

    for(int i=0; i<=4; i++){
    h_[i]+=19ULL*carry;
    carry  = h_[i] >> 51;
    h_[i] &= mask;
	i == 4 ? h_[0] +=carry : h_[i+1] +=carry;
    }
    
    for (int i=0; i<5; i++)
	h[i] = h_[i];

}
