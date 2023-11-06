void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5] = {0};
    uint128_t f_values[4][5];
    uint64_t carry;

    for(int i = 0; i < 5; ++i)
	{
		f_values[0][i] = (uint128_t) f[i];
	}
    for(int i = 0; i < 2; ++i)
    {
		f_values[i+1][i] = f_values[0][i] << 1;
	}
	F_values[1][2] = 38ULL*f_values[0][1];
	F_values[1][3] = 38ULL*f_values[0][2];
	F_values[1][4] = 38ULL*f_values[0][3];
	F_values[2][3] = 19ULL*f_values[0][3];
	F_values[2][4] = 19ULL*f_values[0][4];

    r[0] = f_values[0][0]*f_values[0][0] + f_values[1][4]*f[4] + f_values[1][3]*f_values[0][2];
    r[1] = f_values[1][0]*f_values[0][1] + f_values[1][4]*f_values[0][3] + f_values[2][3]*f_values[0][2];
    r[2] = f_values[1][0]*f_values[0][2] + f_values[0][1]*f_values[0][1] + f_values[1][4]*f[4];
    r[3] = f_values[1][0]*f_values[0][3] + f_values[1][1]*f_values[0][2] + f_values[2][4]*f[4];
    r[4] = f_values[1][0]*f_values[0][4] + f_values[1][1]*f_values[0][3] + f_values[0][2]*f_values[0][2];

    for(int i = 0; i < 5; ++i)
    {
		uint64_t carry = (r[i] >> 51);
	    r[i] = ((uint64_t)r[i]) & mask;
	    r[i+1] += carry;        
	}
	r[0] += 19ULL * (r[4] >> 51);
	
    uint64_t carry_2;
    
	for(int i = 0; i < 3; ++i)
	{
		carry_2 = (r[i] >> 51);
	    r[i] &= mask;
	    r[i+1] += carry_2;
	}

    for(int i = 0; i < 5; ++i)
    {
		h[i] = (uint64_t)r[i];
	}
}