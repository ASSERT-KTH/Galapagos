void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[] = {0, 0, 0, 0, 0};
    uint128_t f_arr[] = {(uint128_t) f[0], (uint128_t) f[1], (uint128_t) f[2], (uint128_t) f[3], (uint128_t) f[4]}; 
    uint128_t multiple_arr[] = {f_arr[0] << 1, f_arr[1] << 1, 38 * f_arr[1], 38 * f_arr[2], 38 * f_arr[3], 19 * f_arr[3], 19 * f_arr[4]};
    uint64_t carry;
    uint64_t tempResult;

    r[0] =   f_arr[0] * f_arr[0] + multiple_arr[2] * f_arr[4] + multiple_arr[3] * f_arr[3];
    r[1] = multiple_arr[0] * f_arr[1] + multiple_arr[3] * f_arr[4] + multiple_arr[5] * f_arr[3];
    r[2] = multiple_arr[0] * f_arr[2] +    f_arr[1] * f_arr[1] + multiple_arr[4] * f_arr[4];
    r[3] = multiple_arr[0] * f_arr[3] +  multiple_arr[1] * f_arr[2] + multiple_arr[6] * f_arr[4];
    r[4] = multiple_arr[0] * f_arr[4] +  multiple_arr[1] * f_arr[3] +    f_arr[2] * f_arr[2];

    for(int i=0; i<5; i++)
    {
        tempResult = ((uint64_t) r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);
        r[(i+1)%5] +=carry;
        h[i] = ((uint64_t) r[i]) & mask;
        carry = (uint64_t) (h[i] >> 51);
        h[(i+2)%5] += carry;
        h[i] = h[i] & mask;
    }
}