fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_val[10];
    int32_t g_val[10];
    int32_t g_times19[10];
    int64_t h_val[10];
    int64_t carry_val[10];

    for(int i=0; i<10; i++){
        f_val[i] = f[i];
        g_val[i] = g[i];
    }

    for(int i=1; i<10; i++){
        g_times19[i] = 19 * g_val[i];
    }

    for (int i=0; i<10; i++){
        int64_t f0g = 0;
        for(int j=0; j<=i; j++){
            f0g += f_val[j]*((int64_t) g_val[i-j]);
            if(j!=0 && j!=i) f0g += f_val[j]*((int64_t) g_val[i-j]);
            if(i-j!=0 && i-j!=9 && j!=0 && j!=9) f0g += f_val[j] * (int64_t) (g_times19[i-j]);
            if(i+j==9 && j!=0 && j!=9) f0g += f_val[j] * (int64_t) (g_times19[i-j]);
        }
        h_val[i] = f0g;
    }    

    for(int i=0; i<10; i++) {
        int64_t carry=0;
        if(i%2==0){
            carry = (h_val[i] + (int64_t)(1L << 25)) >> 26;
        } else {
            carry = (h_val[i] + (int64_t)(1L << 24)) >> 25;
        }               
        h_val[i+1] += carry;
        h_val[i] -= carry * ((uint64_t) (1L << ( 26 - (i%2) )) );
       
        if(i==9){
            h_val[0] += carry * 19;
            h_val[i] -= carry * ((uint64_t) 1L << 25);
        }
        
        carry_val[i] = carry;
    }
    
    for(int i=0; i< 10; i++){
        h[i] = (int32_t)h_val[i];
    }
}
