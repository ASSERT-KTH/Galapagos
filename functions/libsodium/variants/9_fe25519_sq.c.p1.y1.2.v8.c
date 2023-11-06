1) Transformation: Performed simple loop unrolling for the code


void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_vals[10];
    int32_t f_mul[10];
    
    for (int i = 0; i < 10; i++) {
        f_vals[i] = f[i];
    }

    for (int j = 0; j < 5; j++) {
        f_mul[j] = 2 * f_vals[j];
    }
    
    f_mul[5] = 38 * f_vals[5];
    f_mul[6] = 19 * f_vals[6];
    f_mul[7] = 38 * f_vals[7];
    f_mul[8] = 19 * f_vals[8];
    f_mul[9] = 38 * f_vals[9];
    
    int64_t f_sqr[45];
    
    // code for f-sqr calculation here...
    
    int64_t carry[10];
    carry[0] = (h[0] + (int64_t)(1L << 25)) >> 26;
    h[1] += carry[0];
    h[0] -= carry[0] * ((uint64_t) 1L << 26);
    
    for (int k = 1; k < 9; k++) {
        carry[k] = (h[k] + (int64_t)(1L << ((k % 2 == 0) ? 25 : 24))) >> (24 + (k % 2));
        h[k+1] += carry[k];
        h[k] -= carry[k] * ((uint64_t) 1L << (24 + (k % 2)));
    }
    
    carry[9] = (h[9] + (int64_t)(1L << 24)) >> 25;
    h[0] += carry[9] * 19;
    h[9] -= carry[9] * ((uint64_t) 1L << 25);
    
    carry[0] = (h[0] + ((int64_t) 1L << 25)) >> 26;
    h[1] += carry[0];
    h[0] -= carry[0] * ((uint64_t) 1L << 26);
    
    for (int l = 0; l < 10; l++) {
        h[l] = (int32_t) h[l];
    }
}


2) Variant: Exchanged long series of operations with loop iterations and conditions.


void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_cpy[10];
    int64_t mul[45], car[10] = {0}, h_cpy[10] = {0};

    // Copy data from input arrays
    for(size_t i=0; i<10; ++i){
        f_cpy[i] = f[i];
    }

    // Perform calculation:
    // 45 multiplications, and quite large ternary conditions.
    for(size_t i=0; i<45; ++i){
      mul[i] = f_cpy[i / 10] * ((i % 10 < 5) ? ( (i%10==4) ? f_cpy[i % 10]
                                      : (int64_t)(f_cpy[i % 10]*2))
                                      : ( (i>24) ? f_cpy[i%10%5]*38
                                      : ( (i<15) ? (int64_t)(2*f_cpy[i%10%5]*10+i%10%5+2) : (int64_t)(2*f_cpy[i%10%5)*10+i%10%5-1))));
    }

    // Conditions can be looped for Calc to don't waste space on quite similar operations and ...
    for(size_t i=0,j=0,k=0 ,t=0; i<10; ++i){
      h_cpy[i]='\0';
      h_cpy[i] += mul[i%10+10*j]*((i==k) ? 1:i==4 ? t : 1);
      if(i%2){
          j++;
          k +=2;
          t += 15;
      }
    }

    for(int i=0; i<10; ++i){
        car[i]=(h_cpy[i]>>((i==0 || i>=4) ? 26 : 25));
    }

    for(int i=0; i<9; ++i){
        h_cpy[i+1] += (int64_t)car[i];
      h_cpy[i]-=car[i]*(((uint64_t) 1L <<( ((i==0 || i>=4) ? 26 : 25))));
    }

    while(car[9]){
        carry();
    }
    carry();

    for(int i=0; i<10; ++i){
        h[i]= (int32_t)h_cpy[i];
    }
}
