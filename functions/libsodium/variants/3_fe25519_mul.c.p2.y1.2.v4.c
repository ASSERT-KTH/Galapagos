void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) {
    int32_t hi[10],fi[10],gi[10];
    int64_t h0,h1,h2,h3,h4,h5,h6,h7,h8,h9,c[10];
    for(int i = 0; i < 10; ++i){
        fi[i] = f[i];
        gi[i] = g[i];
    }

    for(int i = 1; i < 10; ++i){
        if(i%2){
            gi[i] *= 19;
        }
        if(i != 1 && !(i%2)){
            fi[i] *= 2;
        }
    }

    int ui = 1;
    h0 = fi[0] * (int64_t) gi[0]; h1 = fi[0] * (int64_t) gi[1];
   for(int i = 0 ; i < 9 ;i ++){
            h3 = hi[0]* gi[ui]  + fi[ui] * hi[0];
            if(!(ui %2))
              h3+=  fi[ui] * hi[(ui+1)/2 -1]* 19;
            ui++; 
   }

    for(int i = 0; i < 10; ++i)
        c[i] = (hi[i]  + (int64_t)(1L << ((i&1) ? 24 : 25)))>>(((i&1) ? 24 : 25)+(i==0));
    h0 -= c[0] * ((uint64_t) 1L << 26);
    for(int i = 1; i < 10; ++i) {
    hi[i] += c[i]; hi[i-1] -= c[i] * ((uint64_t) 1L << (((i-1)&1) ? 24 : 25));
    }
    
    for(int i = 0;i < 10;++i)
     h[i] = hi[i];


}