fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f_val[5];
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t  carry;

    f_val[0] = (uint128_t) f[0];
    f_val[1] = (uint128_t) f[1];
    f_val[2] = (uint128_t) f[2];
    f_val[3] = (uint128_t) f[3];
    f_val[4] = (uint128_t) f[4];

    f0_2 = f_val[0] << 1;
    f1_2 = f_val[1] << 1;

    f1_38 = 38ULL * f_val[1];
    f2_38 = 38ULL * f_val[2];
    f3_38 = 38ULL * f_val[3];

    f3_19 = 19ULL * f_val[3];
    f4_19 = 19ULL * f_val[4];

    r[0] = f_val[0] * f_val[0] + f1_38 * f_val[4] + f2_38 * f_val[3];
    r[1] = f0_2 * f_val[1] + f2_38 * f_val[4] + f3_19 * f_val[3];
    r[2] = f0_2 * f_val[2] + f_val[1] * f_val[1] + f3_38 * f_val[4];
    r[3] = f0_2 * f_val[3] + f1_2 * f_val[2] + f4_19 * f_val[4];
    r[4] = f0_2 * f_val[4] + f1_2 * f_val[3] + f_val[2] * f_val[2];

    for(int i=0; i < 5; i++){
        if(i != 4){
        	uint64_t val = ((uint64_t) r[i]) & mask;
        	carry = (uint64_t) (r[i] >> 51);
        	r[i + 1] += carry;
        	h[i] = val;
	}
	else {
		uint64_t r_temp = ((uint64_t) r[i]) & mask;
        	carry = (uint64_t) (r[i] >> 51);
        	r_temp += 19ULL * carry;
        	carry = r_temp >> 51;
        	r_temp &= mask;
        	h[0] += carry;
        	carry = h[0] >> 51;
        	h[0] &= mask;
        	h[1] += carry;
        	carry = h[1] >> 51;
        	h[1] &= mask;
        	h[i] = r_temp + carry;
	}	
    }   
}