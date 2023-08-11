fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    fing the values shifts and multiplies

	f0_2 = f0 * 2;
    f1_2 = f1 * 2;
 
    f1_38 = f1 * 38;                 
    f2_38 = f2 * 38;
    f3_38 = f3 * 38;

    f3_19 = f3 * 19;  
    f4_19 = f4 * 19;  

    Computing the values using changed multiplication orders
    
	r0 =  f0 * f0 + f4 * f1_38 + f3 * f2_38;               
    r1 = f1 * f0_2 + f4 * f2_38 + f3 * f3_19;  
    r2 = f2 * f0_2 + f1 * f1 + f4 * f3_38;   
    r3 = f3 * f0_2 + f2 * f1_2 + f4 * f4_19;   
    r4 = f4 * f0_2 + f3 * f1_2 + f2 * f2; 

    Performing the and, shift, add operations

    
    r00    = r0 & mask;
    carry  = r0 >> 51;
    r1    += carry;
    r01    = r1 & mask;
    carry  = r1 >> 51;
    r2    += carry;
    r02    = r2 & mask;
    carry  = r2 >> 51;
    r3    += carry;
    r03    = r3 & mask;
    carry  = r3 >> 51;
    r4    += carry;
    r04    = r4 & mask;
    carry  = r4 >> 51;
    r00   += carry * 19;
    carry  = r00 >> 51;
    r00   &= mask;
    r01   += carry;
    carry  = r01 >> 51;
    r01   &= mask;
    r02   += carry;

    Setting values to the array 
	
	h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}