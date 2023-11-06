void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t accumulators[5];
    uint64_t capitalized_f[4], capitalized_g[5];
    uint64_t reducer, temp[5];

    for(int i = 0; i<5; i++){
        capitalized_g[i] = (uint128_t) g[i];
    }

    for(int i = 1; i<5; i++){
        capitalized_f[i - 1] = 19ULL * (uint128_t)f[i];
    }
    
    for(int i = 0; i<5; i++){
        accumulators[i] = 0;
    }

    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            accumulators[(i+j)%5] += (j < i? capitalized_f[4 - (i-j)] : (uint128_t)f[j - i]) * capitalized_g[(i+j)%5];
        }
    }
    
    temp[0] = accumulators[0] & mask;
    reducer = accumulators[0] >> 51;
    
    for(int i = 1; i<5; i++){
        accumulators[i] += reducer;
        temp[i] = accumulators[i] & mask;
        reducer = accumulators[i] >> 51;
    }
    
    temp[0] += 19ULL * reducer;
    reducer = temp[0] >> 51;
    temp[0] &= mask;

    for(int i = 1; i<3; i++){
        temp[i] += reducer;
        reducer = temp[i] >> 51;
        temp[i] &= mask;
    }

    for(int i = 0; i<5; i++){
        h[i] = temp[i];
    }
}