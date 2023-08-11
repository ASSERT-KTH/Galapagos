fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t temp_generic_storage[12];
    uint64_t carry, gen_car;
    uint128_t product_constant = 19ULL;
    
    for(int i=0; i<5; i++){
        temp_generic_storage[i] = (uint128_t) f[i]; //Keeping f in a generic temp storage
        temp_generic_storage[i+5] = (uint128_t) g[i]; //Keeping g in a generic temp storage
        temp_generic_storage[i+7] = product_constant * f[i]; //Keeping 19* f in a generic temp storage
    }

    for(int iterator=0; iterator<5; iterator++){ //Making the computation using helper storage without changing functionality

        temp_generic_storage[12] = temp_generic_storage[12] + 
                                  temp_generic_storage[(   iterator)%5] *
                                  temp_generic_storage[(   iterator)%5 + 5] +
                                  temp_generic_storage[(1+ iterator)%5 + 7] *
                                  temp_generic_storage[(4+ iterator)%5 + 5] +
                                  temp_generic_storage[(2+ iterator)%5 + 7] *
                                  temp_generic_storage[(3+ iterator)%5 + 5] +
                                  temp_generic_storage[(3+ iterator)%5 + 7] *
                                  temp_generic_storage[(2+ iterator)%5 + 5] +
                                  temp_generic_storage[(4+ iterator)%5 + 7] *
                                  temp_generic_storage[(1+ iterator)%5 + 5];

        carry  = (temp_generic_storage[12] >> 51);
        temp_generic_storage[(iterator+1)%5] = ((uint64_t) temp_generic_storage[12]) & mask;
        temp_generic_storage[12+iterator+1] = temp_generic_storage[((iterator+1)%5)];
        temp_generic_storage[12] = 0;
        temp_generic_storage[(iterator+1)%5 +1] += carry;
        
        gen_car = temp_generic_storage[12 + (iterator+1) % 5] >> 51;
        temp_generic_storage[12 + (iterator+1) % 5] &= mask;
        temp_generic_storage[(iterator+1)%5 +2] += gen_car;

    }
    for(int looping=0;looping<5;looping++){       //Assigning values back
        h[looping] = temp_generic_storage[12 + looping];
    }
}