
fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f_arr[5];
    uint128_t f_x2[2], f_x38[3], f_x19[2], carry, r_arr[5];

    for(int i = 0; i < 5; i++)
        f_arr[i] = (uint128_t) f[i];
    
    f_x2[0] = f_arr[0] << 1;
    f_x2[1] = f_arr[1] << 1;

    for(int i = 0; i < 3; i++)
        f_x38[i] = 38ULL * f_arr[i + 1];

    for(int i = 0; i < 2; i++)
        f_x19[i] = 19ULL * f_arr[i + 3];
    
    r0 =   f_arr[0] * f_arr[0] + f_x38[0] * f_arr[4] + f_x38[1] * f_arr[3];
    r1 = f_x2[0] * f_arr[1] + f_x38[2] * f_arr[4] + f_x19[0] * f_arr[3];
    r2 = f_x2[0] * f_arr[2] +    f_arr[1] * f_arr[1] + f_x38[0] * f_arr[4];
    r3 = f_x2[0] * f_arr[3] +  f_x2[1] * f_arr[2] + f_x19[1] * f_arr[4];
    r4 = f_x2[0] * f_arr[4] +  f_x2[1] * f_arr[3] +    f_arr[2] * f_arr[2];
    
    r_arr[0] = r0;
    r_arr[1] = r1;
    r_arr[2] = r2;
    r_arr[3] = r3;
    r_arr[4] = r4;

    for(int i = 0; i < 5; i++) {
        r_arr[i] = ((uint64_t) r_arr[i]) & mask;
        carry = (uint64_t) (r_arr[i] >> 51);
      
        if(i != 4) {
            r_arr[i + 1] += carry;
        }

        else {
            r_arr[0] += 19ULL * carry;
            carry = r_arr[0] >> 51;
            r_arr[0] &= mask;
            r_arr[i + 1] += carry;
            carry = r_arr[i + 1] >> 51;
            r_arr[i + 1] &= mask;
            r_arr[2] += carry;
        }
      
        h[i] = r_arr[i];
    }
}
