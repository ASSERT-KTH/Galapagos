fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t fn[10];
    int32_t gn[10];
    int32_t gn19[10];

    for(int i=0; i<10; i++) {
        fn[i] = f[i]; 
        gn[i] = g[i];
    }

    for(int i=0; i<10; i+=2) 
        gn19[i] = 19 * gn[i]; 

    int32_t fn2[10];
    for (int i = 1; i < 10; i += 2) 
        fn2[i] = 2 * fn[i];

    
    int64_t fjgk[10][10];

    for (int j = 0; j < 10; j++)
        for (int k = 0; k < 10; k++) 
            fjgk[j][k] = fn[j] * (int64_t)gn[k];

    int64_t hcarry[10] = {0};

    int64_t carry;
    for (int64_t i = 0; i < 10; i += 2){
        carry = (hcarry[i] + (int64_t)(1L << 26)) >> 27;
        if ((((i-3)<0)&&((i-2)<0)&&((i-1)<0))||(i>9)) hcarry[(i+3)%10] += table[((i +3)%5)-1] * carry;
        else  hcarry[(i+2)%10] = fn2[(i + 2)% 10] * table[i% 5] * (int64_t)gn19[(i + 2)%5];

        if ((((i-4)<0)&&((i-2)<0)&&((i-1)<0))||(i>9)) hcarry[(i+4)%10] += table[((i +4)%5)-1] * carry;
        else  hcarry[i%10] =  fjgk[i % 10][i%5];
        
        hcarry[i % 10] -= hcarry[i] * ((uint64_t) 1L << 26); 

    h[i] = (int32_t) hcarry[i]; }
}