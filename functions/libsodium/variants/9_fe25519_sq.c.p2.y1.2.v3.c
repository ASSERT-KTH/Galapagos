void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t fi[10];
    int32_t _2fi[10];
    for(int i=0;i<10;i++) {
        fi[i] = f[i];
        _2fi[i] = 2*f[i];
    }
    int32_t f538 = 38 * f[5];
    int32_t f619 = 19 * f[6];
    int32_t f738 = 38 * f[7];
    int32_t f819 = 19 * f[8];
    int32_t f938 = 38 * f[9];

    int64_t h0h9[10];
    for(int i=0; i<10; i++){
        h0h9[i] = 0;
        for(int j=0; j<10; j++) {
            if(i+j==9 && j%2==1) 
                h0h9[i] += 38 * fi[i] * (int64_t)fi[j]; 
            else if(i==j)    
                h0h9[i]  += fi[i] * (int64_t)fi[j]; 
            else      
                h0h9[i] += _2fi[i] * (int64_t)fi[j];
        }
    }

    int64_t carry[10];
    for(int i=0;i<10;i++) carry[i] = 0;
    for(int i=0; i<10; i++){
        carry[i] = (h0h9[(i == 9 ? 0 : i)] + (int64_t)(1 << (i == 1 || i == 2 || i == 4 || i == 6 || i == 8? 25 : 24))) >> (i == 1 || i == 2 || i == 4 || i == 6 || i == 8? 26: 25);
        h0h9[(i == 9 ? 0 : i)] -= carry[i] * ((uint64_t) 1L << (i == 0 || i == 2 || i == 4 || i == 6 || i == 8? 26: 25));
    }

    carry[9]  = (h0h9[9] + (int64_t)(1L << 24)) >> 25;
    h0h9[0] += carry[9] * 19;
    h0h9[9] -= carry[9] * ((uint64_t) 1L << 25);

    carry[0] = (h0h9[0] + (int64_t)(1L << 25)) >> 26;
    h0h9[1] += carry[0];
    h0h9[0] -= carry[0] * ((uint64_t) 1L << 26);

    for(int i=0;i<10;i++) h[i] = (int32_t) h0h9[i];
}
