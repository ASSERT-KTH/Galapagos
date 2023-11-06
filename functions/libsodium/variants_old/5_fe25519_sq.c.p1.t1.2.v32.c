
void fe25519_sq(fe25519 h, const fe25519 f) {
    uint128_t f[5], r[5] = {0};
    uint64_t fc[10], rC[10] = {0}, carry;
    uint64_t mask = 0x7ffffffffffffULL;
    int i;

    for (i=0; i<5; i++) fc[i] = (uint128_t) f[i];

    fc[5] = 19 * fc[4];
    fc[6] = 19 * fc[3];
    fc[7] = 38 * fc[2];
    fc[8] = 38 * fc[1];
    fc[9] = 38 * fc[0];

    for (i=0; i<5; i++) {
        int j;
        for(j=0; j<=i; j++) { r[i+j] += fc[i-j] * fc[j]; }
        for (j=i+1; j<5; j++) { r[i+j] = r[i+j] + 2 * fc[i-j] * fc[j]; }		
    }

    for (i=0; i<5; i++) {
        rC[i] = r[i] & mask;
        carry = (uint64_t) (r[i] >> 51);
        r[i+1] += carry;
    }        

    for (i=0; i<4; i++) {
        carry = r[i] >> 51; 
        r[i] &= mask;
        r[i+1] += carry;
    }
        
    carry = (r[4] >> 51);
    rC[0] += 19ULL * carry;		
    r[5] &= mask;    
        
    carry = rC[0] >> 51; 
    rC[0] &= mask;		
    rC[1] += carry;

    for (i=0; i<5; i++) h[i] = r[i];
}
