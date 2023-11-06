void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t entry_array[5];
    uint128_t doubled_array1[2];
    uint128_t mult_array1[3];
    uint128_t mult_array2[2];
    uint64_t h_array[5];
    uint64_t carry;

    for(int i = 0; i < 5; i++)
        entry_array[i] = (uint128_t)f[i];

    for(int i = 0; i < 2; i++)
        doubled_array1[i] = entry_array[i] << 1;

    for(int i = 1; i < 4; i++)
        mult_array1[i - 1] = 38ULL * entry_array[i];

    for(int i = 3; i < 5; i++)
        mult_array2[i - 3] = 19ULL * entry_array[i];

    r0 =   entry_array[0] * entry_array[0] + mult_array1[0] * entry_array[4] + mult_array1[1] * entry_array[3];
    r1 = doubled_array1[0] * entry_array[1] + mult_array1[1] * entry_array[4] + mult_array2[0] * entry_array[3];
    r2 = doubled_array1[0] * entry_array[2] +    entry_array[1] * entry_array[1] + mult_array1[2] * entry_array[4];
    r3 = doubled_array1[0] * entry_array[3] +  doubled_array1[1] * entry_array[2] + mult_array2[1] * entry_array[4];
    r4 = doubled_array1[0] * entry_array[4] +  doubled_array1[1] * entry_array[3] +    entry_array[2] * entry_array[2];

    uint128_t r_numbers[5] = {r0, r1, r2, r3, r4};

    for(int i = 0; i < 5; i++){
        h_array[i] = ((uint64_t) r_numbers[i]) & mask;
        carry  = (uint64_t) (r_numbers[i] >> 51);
        if(i != 4) r_numbers[i+1] += carry;
        else h_array[0] += 19ULL * carry;
        carry = h_array[i] >> 51;
        h_array[i] &= mask;
        if(i != 3) h_array[i+1] += carry;
    }
    
    h_array[2] += carry;

    for(int i = 0 ; i < 5; i++) h[i] = h_array[i];
}
This version uses for loops which in reality is slightly less efficient than the original but matches in practical functionality.
