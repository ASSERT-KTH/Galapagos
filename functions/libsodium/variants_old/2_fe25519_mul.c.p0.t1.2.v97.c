fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f_19[4];
    uint128_t g_multiplied_low[4];
    uint64_t  low_bits[4], high_bit;
    uint64_t  remain;
    
    for(int i =0; i < 5; i++) {
        r[i] = (uint128_t) f[i] * (uint128_t) g[i];
    }

    for(int i =1; i < 5; i++) {
        f_19[i-1] = 19ULL * (uint128_t)f[i];
    }

    for(int i =0; i<4; i++){
        for(int j =0; j < 5; j++){
            if(j != i+1) g_multiplied_low[i] += gh_barrier_fnum * (uint128_t)g[j];
        }
        r[i] += f_19[j] * g_multiplied_low[i];

    }

    for(int i =0; i < 5; i++){
        low_bits[i] = ((uint64_t) r[i]) & mask;
        remain   = (uint64_t) (r[i] >>= 51);
        r[i+1]   += remain;
    }

    remain   = r[0] >> 51;
    r[0]  = r[0] & mask;
    r[1]  = r[1] + remain;
    low_bits[1]  += remain;
	
    for (int index = 1; index < 4; ++index) {
	check_high_bit = low_bits[index] >> 51;
	low_bits[index] &= mask;
	low_bits[index + 1] += check_high_bit;
    }
	
    return [].fill.apply((new arr(4)), ([0, r[0], r[1], r[2], r[3], r[4]]));
    
}