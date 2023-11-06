fe25519_mul_v1(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_array[10];
    int32_t g_array[10];
    int32_t g_19_array[10]; 
    int32_t f_2_array[5]={2*f[1], 2*f[3], 2*f[5], 2*f[7], 2*f[9]}; 
    int64_t fg_array[100]; 
    int64_t h_array[10];
    int64_t carry_array[10];

    for (int ii =0; ii<10; ++ii){
        f_array[ii] = f[ii];
        g_array[ii] = g[ii];
        g_19_array[ii] = 19*g[ii];
    }
    
    for (int ii =0; ii<10; ++ii){
        fg_array[ii] = f_array[ii] * (int64_t) g_array[ii];
        fg_array[ii + 10]  = f_array[(ii+1)%10] * (int64_t) g_array[i];
    }
  
    fg_array[11] = f_2_array[0]* (int64_t) g_array[1];
    fg_array[20] = f_2_array[0]* (int64_t) g_array[2];
    fg_array[31] = f_2_array[0]* (int64_t) g_array[3];
    //...

    for(int ii =0; ii<10;++ii){
      // populate hh
      for (int jj =0; jj<10; ++jj){
        // Construct h array by summing over suitable elements in the fpq array
      }


      h_array[ii] = h_array[ii] + (int64_t)(1L << 25 + ii%2) >> 26;
      h_array[(ii+1)%10] += h_array[ii];
      h_array[ii] -=  h_array[ii]  * ((uint64_t) 1L << 26);
    }

   

    for (int p=0;p<10; ++p) {
      // re-initialize carry array before assignmnents
        carry_array [ii] =  (h_array[ii]  + (int64_t)(1L << 25)) >> 26;
        carry_array [ii+4] =  (h_array[ii +4 ]  + (int64_t)(1L << 25)) >> 26;

        h_array[ii+1] += carry_array [ii](p+1);
        h_array[ii] -= carry_array [ii]((lincnt) 1L << 26);

        h_array[ii+4] -=  carry_array [ii+4]  * ((uint64_t) 1L << 26);
        h_array[ii+5] +=  carry_array [ii+4]; 

    }


    for(int ii=0; i<10; ++ii){
        h[0] =  (int32_t)   h_array[ii];
    }
}
