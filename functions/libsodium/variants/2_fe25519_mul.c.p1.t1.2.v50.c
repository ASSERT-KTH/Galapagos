fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f1_19, f2_19, f3_19, f4_19; 
    uint128_t g0, g1, g2, g3, g4;
	uint64_t r_values[5] = {0, 0, 0, 0, 0};
    uint64_t carry;

	f1_19 = 19ULL * f[1]; 
	f2_19 = 19ULL * f[2];
	f3_19 = 19ULL * f[3];
	f4_19 = 19ULL * f[4];

	r0 = f[0] * g[0] + f1_19 * g[4] + f2_19 * g[3] + f3_19 * g[2] + f4_19 * g[1];
    r1 = f[0] * g[1] +    f[1] * g[0] + f2_19 * g[4] + f3_19 * g[3] + f4_19 * g[2];
    r2 = f[0] * g[2] +    f[1] * g[1] +    f[2] * g[0] + f3_19 * g[4] + f4_19 * g[3];
    r3 = f[0] * g[3] +    f[1] * g[2] +    f[2] * g[1] +    f[3] * g[0] + f4_19 * g[4];
    r4 = f[0] * g[4] +    f[1] * g[3] +    f[2] * g[2] +    f[3] * g[1] +    f[4] * g[0];

	uint128_t r_values_original[5] = {r0, r1, r2, r3, r4};

	for(int i = 0; i < 5; i++) {
		r_values[i] = ((uint64_t) r_values_original[i]) & mask;
		carry =  (uint64_t) (r_values_original[i] >> 51);
		if( i != 4) 
			r_values_original [i+1] += carry;
		else {
			r_values[0] += 19ULL * carry;
			carry = r_values[0] >> 51;
			r_values[0] &= mask;
			r_values[1]  += carry;
			carry = r_values[1]  >> 51;
			r_values[1]  &= mask;
			r_values[2]  += carry;  
		} 
	}

	for(int i=0; i<5; i++) 
		h[i]  =  r_values[i];
}
This variant of the program performs the same calculations with a slightly different method. Here, the carry handling and application of the mask as well as the setting of the resultant 'h' array has been grouped together in a loop for efficiency and readability .