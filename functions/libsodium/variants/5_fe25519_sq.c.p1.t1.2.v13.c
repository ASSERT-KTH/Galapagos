
void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f_arr[10];
    uint64_t carry;

    for(uint16_t i=0; i < 5; i++)
    {
        f_arr[i] = (uint128_t) f[i];
    }

    f_arr[5] = f_arr[0] << 1;
    f_arr[6] = f_arr[1] << 1;

    f_arr[7] = 38ULL * f_arr[1];
    f_arr[8] = 38ULL * f_arr[2];
    f_arr[9] = 38ULL * f_arr[3];

    r[0]  =  f_arr[0] * f_arr[0] +     f_arr[7] * f_arr[4] + f_arr[8] * f_arr[9];
    r[1]  = f_arr[5] * f[1] +        f_arr[8] * f_arr[4] + 19ULL * f_arr[9];
    r[2]  = f_arr[5] * f_arr[2] + f_arr[1] * f_arr[1] + f_arr[9] * f_arr[4];
    r[3]  = f_arr[5] * f_arr[3] + f_arr[6] * f_arr[2] + 19LL * f[4] * f[4];
    r[4]  = f_arr[5] * f_arr[4] + f_arr[6] * f_arr[3] + f_arr[2] * f_arr[2];

    for (uint16_t i = 0; i < 5; i++)
    {
        h[i] = ((uint64_t) r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);

        if(i != 4)
        {
            r[i + 1] += carry;
            h[i] = ((uint64_t)r[i]) & mask;
        }
        else 
        {
            h[0] += 19ULL * carry;
            h[i] = ((uint64_t)r[i]) & mask;
            carry = h[i] >> 51;
            h[i] &= mask;
            h[i - 4] += carry;
            carry = h[i - 4] >> 51;
            h[i - 4] &= mask;
            h[i - 3] += carry;
        }
    }  
}
    
This variant performs the same operations to compute the arithmetic over the finite field (field with 2^255 - 19 elements). But it changes the behavior of the original function by storing the fi and ri values in arrays, and by implementing loops to replace some repetitions in the code.