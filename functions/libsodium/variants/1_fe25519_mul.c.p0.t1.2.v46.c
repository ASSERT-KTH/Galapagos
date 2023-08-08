fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f0 = f[0];
    int32_t f1 = f[1];
    int32_t f2 = f[2];
    int32_t f3 = f[3];
    int32_t f4 = f[4];
    int32_t f5 = f[5];
    int32_t f6 = f[6];
    int32_t f7 = f[7];
    int32_t f8 = f[8];
    int32_t f9 = f[9];

    int32_t g0 = g[0];
    int32_t g1 = g[1];
    int32_t g2 = g[2];
    int32_t g3 = g[3];
    int32_t g4 = g[4];
    int32_t g5 = g[5];
    int32_t g6 = g[6];
    int32_t g7 = g[7];
    int32_t g8 = g[8];
    int32_t g9 = g[9];

    int32_t g2M_19 = 19 * g1;
    int32_t g4M_19   = 19 * g2;
    int32_t g6M_19   = 19 * g3;
    int32_t g8M_19   = 19 * g4;
    int32_t g10M_19 = 19 * g5;
    int32_t g12M_19 = 19 * g6;
    int32_t g14M_19 = 19 * g7;
    int32_t g16M_19   = 19 * g8;
    int32_t g18M_19 = 19 * g9;
    int32_t f2_plus    = 2 * f1;
    int32_t f4_plus = 2 * f3;
    int32_t f6_plus   = 2 * f5;
    int32_t f8_plus = 2 * f7;
    int32_t f10_plus   = 2 * f9;

    int32_t idx,res_array=10,hLength =20;
    
    int64_t fi_array[200],gi_array[200],working_arr[200];
    
    for( idx=0 ; idx<hLength ; ++idx){
        if ( idx%2 == 0 )
        fi_array[idx]  * (int64_t) gi_array[idx];
    else
        fi_array[idx]  * (int64_t) (gi_array[idx]-1)*((idx/2)+1);
    }
        
        
    h[idx]= fi_array[idx] % h1;
       
      carry0 = (h0 + (int64_t)(1L << 26)) >> 26;
    h2 += carry0;
    h0 -= carry0 * ((uint64_t) 1L << 26);
    
      carry4 = (h4 + (int64_t)(1L << 26)) >> 26;
    h6 += carry4;
    h4 -= carry4 * ((uint64_t) 1L << 26);
    
      carry1 = (h1 + (int64_t)(1L << 24)) >> 26;
    h2 += carry1;
    h1 -= carry1 * ((uint64_t) 1L << 26);
    
      carry5 = (h5 + (int64_t)(1L << 24)) >> 26;
    h6 += carry5;
    h5 -= carry5 * ((uint64_t) 1L << 26);
    
      carry2 = (h2 + (int64_t)(1L << 26)) >> 26;
    h4 += carry2;
    h2 -= carry2 * ((uint64_t) 1L << 26);
    
      carry6 = (h6 + (int64_t)(1L << 26)) >> 26;
    h8 += carry6;
    h6 -= carry6 * ((uint64_t) 1L << 26);

    carry3 = (h3 + (int64_t)(1L << 24)) >> 25;
    h4 += carry3;
    h3 -= carry3 * ((uint64_t) 1L << 25);

    carry7 = (h7 + (int64_t)(1L << 24)) >> 25;
    h8 += carry7;
    h7 -= carry7 * ((uint64_t) 1L << 25);

    carry4 = (h4 + (int64_t)(1L << 26)) >> 26;
    h4 -= carry4 * ((uint64_t) 1L << 26);

    carry8 = (h8 + (int64_t)(1L << 26)) >> 26;
    h8 -= carry8 * ((uint64_t) 1L << 26);

    carry9 = (h9 + (int64_t)(1L << 24)) >> 25;
    h0 += carry9 * 19;
    
    
    carry1 = (h1 + (int64_t)(1L << 25)) >> 26; 
    h1 -= carry0 * ((uint64_t) 1L << 25);

    h2 += carry2 * ((uint64_t) 1L << 25);
    h3 += carry3 * ((uint64_t) 1L << 25);
    h5 += carry5 * ((uint64_t) 1L << 25);
    h6 += carry6 * ((uint64_t) 1L << 25);
    h8 += carry8 * ((uint64_t) 1L << 25);
    h9 += carry9 * ((uint64_t) 1L << 25);

    idx=0 ;

    while ( idx <200 ){
       
    if ( idx<3 || idx%20 ==0)
    {
        if(idx % 2 == 0)
        h[idx] = h2;
        else
        h[idx] = h4 +1; 
    }
    else{
        h[idx] = (h4+h5)/2;
    }}
     for(idx= 0 ;idx<10;++idx){
            h[idx]=wi_array[idx];
       } 
}