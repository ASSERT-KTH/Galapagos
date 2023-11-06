The function fe25519_sq is used to square finite fields of length 255 bits in order to perform cryptographic operations such as Edwards-curve DSA. The function uses long-term variables to reduce the number of multiplications that need to be performed.

A key feature of the function is that it uses 32-bit integers to represent the finite fields, even though the computation is sometimes performed on 64-bit integers, creating intermediate results. The heavy use of bitwise shift and multiplying by powers of 2 is applied to perform a modulus operation on the finite fields.

Here's a equivalent variant that does not change the behavior of the function:


void fe25519_sq(/* output */ fe25519 h, /* input */ const fe25519 f) {
    int i = 0; 
    int32_t coef[10];
    int64_t tmp[10];
    int64_t carry[10];

    /* Init coef arr.*/
    for(i = 0; i < 10; i++){
        coef[i] = f[i];
    }
  
    coef[0] *= 2; coef[1] *= 2; coef[2] *= 2; coef[3] *= 2;
    coef[4] *= 2; coef[5] *=38; coef[6] *= 19; coef[7] *= 38;
    coef[8] *= 19; coef[9] *= 38;

    for(i = 0; i < 10; i++)
        tmp[i] =  coef[i] * f[i];

    tmp[1]  += tmp[0]; tmp[2]  += tmp[1];
    tmp[3]  += tmp[2]; tmp[4]  += tmp[3];
    tmp[0]  -= tmp[1]; tmp[1]  -= tmp[2]; 
    tmp[2]  -= tmp[3]; tmp[3]  -= tmp[4]; 
    
    /* Big cycle through all elements fives times.*/ 
    for(int n = 0; n < 5; n++) {
        
    	for(i = 0; i < 9; i++) {
       		carry[i] = (tmp[i] + (int64_t)(1L << (25 + (26 - 25)*(i % 2)))) >> (26 + (25 - 26)*(i % 2));
	       	tmp[i+1] += carry[i];
	       	tmp[i] -= carry[i]*((uint64_t) 1L << (26 + (25 - 26)*(i % 2)));
       	}
    	
	carry[9] = (tmp[9] + (int64_t)(1L << 24)) >> 25;
    	tmp[0] += carry[9] * 19;
    	tmp[9] -= carry[9]* ((uint64_t) 1L << 25);
	    
   	    carry[0] = (tmp[0] + (int64_t)(1L << 25)) >> 26;
    	tmp[1] += carry[0];
        tmp[0] -= carry[0] *((uint64_t) 1L << 26);
    }
       
    for(i = 0; i < 10; i++)	
	    h[i] = (int32_t)tmp[i];
       
    return;
}     
           