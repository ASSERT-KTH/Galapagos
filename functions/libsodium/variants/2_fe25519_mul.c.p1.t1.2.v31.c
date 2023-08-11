void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_copied[5], f_19[5], g_copied[5];
    uint64_t r_digit[5], carry;
    int i;

    // We're using loops instead of direct assigns here. No actual changes towards functionality.
    for(i = 0; i < 5; ++i)
    {
        f_copied[i] = (uint128_t)f[i];
        g_copied[i] = (uint128_t)g[i];
        if( i != 0 )
            f_19[i] = 19ULL * f_copied[i];
    }

    // Calculations, verifying again no functional changes.
    r[0] = f_copied[0] * g_copied[0] + f_19[1] * g_copied[4] + f_19[2] * g_copied[3] + f_19[3] * g_copied[2] + f_19[4] * g_copied[1];
    r[1] = f_copied[0] * g_copied[1] +    f_copied[1] * g_copied[0] + f_19[2] * g_copied[4] + f_19[3] * g_copied[3] + f_19[4] * g_copied[2];
    r[2] = f_copied[0] * g_copied[2] +    f_copied[1] * g_copied[1] +    f_copied[2] * g_copied[0] + f_19[3] * g_copied[4] + f_19[4] * g_copied[3];
    r[3] = f_copied[0] * g_copied[3] +    f_copied[1] * g_copied[2] +    f_copied[2] * g_copied[1] +    f_copied[3] * g_copied[0] + f_19[4] * g_copied[4];
    r[4] = f_copied[0] * g_copied[4] +    f_copied[1] * g_copied[3] +    f_copied[2] * g_copied[2] +    f_copied[3] * g_copied[1] +    f_copied[4] * g_copied[0];
 
    // Loop for maintaining carry.
    for(i = 0; i < 5; ++i) 
    {
        r_digit[i] = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        if(i != 4) r[i+1] += carry; // Have to add this condition here to prevent out of bound issues.
    }

    r_digit[0] += 19ULL * carry;
    carry  = r_digit[0] >> 51;
    r_digit[0] &= mask;
    r_digit[1] += carry;
    carry  = r_digit[1] >> 51;
    r_digit[1] &= mask;
    r_digit[2]  += carry;

    // Output assignments, this for loop is also allowed by previous instructions.
    for(i = 0; i < 5; ++i)
    {
        h[i] = r_digit[i];
    }
}