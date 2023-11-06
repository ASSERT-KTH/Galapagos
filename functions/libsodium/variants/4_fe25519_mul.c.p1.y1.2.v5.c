Variant #1: Redefine constants individually when used


fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) 
{
    uint128_t r[5];
    uint64_t mask = 0x7ffffffffffffULL;

    for(int i = 0; i<5; i++) {
        r[i] = ((uint128_t)f[i]) * ((uint128_t)g[0]) % mask;
        for(int j = 1; j<5; j++) {
            r[i] +=  (((uint128_t)f[(i-j+5)%5]) * (((uint64_t)19) * ((uint128_t)g[j]) % mask)) ; 
        }
    }

    uint64_t carry = 0; 
    for( int i = 0; i<5; i++){ 
        r[i] += carry;
        carry = (r[i]>>51); 
        r[i] &= mask;
    }
    r[0] += 19ULL * carry;
    carry = r[0] >> 51;
    r[0] &= mask;
    r[1] += carry;
    carry = r[1] >> 51;
    r[1] &= mask;
    r[2] += carry;

    for (int i = 0; i < 5; i++)
		h[i] = r[i];
}


Variant #2: Omit mask definition and use it directly 


fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint128_t r[5];
    uint128_t f0, f1, f2, f3, f4;
    uint64_t carry;

    f0 = (uint128_t)f[0]; 
    f1 = (uint128_t)f[1];
    f1 *= (uint64_t)19;
    f2 = (uint128_t)f[2];
    f2 *= (uint64_t)19;
    f3 = (uint128_t)f[3];
    f3 *= (uint64_t)19;
    f4 = (uint128_t)f[4];
    f4 *= (uint64_t)19;

    for (int i = 0 ; i < 5; ++i ) {
        r[i] = f0*g[i];
        for(int j = 1 ; j < 5 ; ++j ) {
            r[i] += (( uint128_t )f[j]) * g[(i-j+5)%5];    
        }
        r[i] &= (0X7ffffffffffff);
        if ( i> 0 ) {
        	r[i] +=  carry;
        }
        carry = r[i] >> 51;
    }

    r[0] += 19ULL * carry;
    carry = r[0] >> 51;
    r[0] &= 0X7ffffffffffff;
    r[1] += carry;
    
    for (int i=0; i<5; i++){
        h[i] = r[i];
    }
}
