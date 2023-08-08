fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t p, q, fp[5], gp[5], p_19[5], rp[5];
    uint64_t  r_p, carry, rg[5];
        
    for (int i = 0; i < 5; i++){
        fp[i] = (uint128_t)f[i];
        gp[i] = (uint128_t)g[i];   
	}

	for(int i = 1; i < 5; i++){
    	p_19[i] = 19ULL * fp[i];
	}

	for(int i = 0; i < 5; i++)
	{
        rp[i] = p_19[(i + 1) % 5] * gp[(5 - i) % 5] + p_19[(i + 2) % 5] * gp[(6 - i) % 5] + p_19[(i + 3) % 5] * gp[(7 - i) % 5] + p_19[(i + 4) % 5] * gp[(i + 1) % 5] + (i != 0 ? fp[(i + 4) % 5] * gp[(5 - i) % 5] : fp[0] * gp[0]);
	}

	for(int i = 0; i < 5; i++){
        rg[i]    = ((uint64_t) rp[i]) & mask;
        carry  = (uint64_t) (rp[i] >> 51);
        if(i != 4) rp[i+1] += carry;
	}

	p = rp[0] + 19ULL * carry;

    rg[0] =  p& mask;
    carry  = p >> 51;
    
	for(int i = 1 ; i < 5; i++){
	    rg[0] += carry;
        carry  = rg[0] >> 51;
        rg[i] += carry;
	}

    for(int i = 0 ; i < 5; i++){
		h[i] = rg[i];
	}
}