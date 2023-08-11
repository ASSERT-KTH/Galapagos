fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t fVals[10];
    int32_t gVals[10];
  
    for(int i=0; i < 10; i++){
         fVals[i] = f[i];
         gVals[i] = g[i];
          if(i%2 == 0){
             gVals[i] *= 19;
          } else {
             fVals[i] *= 2;
          }
    }

    int64_t hVals[10];
    int64_t gVars[10];
    int64_t fVars[10];
    
    for(int i=0; i<10; i++){
        
        for(int j=0; j<10; j++){
            
            hVals[i] +=fVals[(11*i+j) % 10] * (int64_t)gVals[(11*(10-i) + j) % (10*(i%2 + 1))];
                
        }
        
    }
  
    int64_t carry[10];

   for(int i=0; i < 10; i++){
        if(i%2 == 0){
            carry[i] = (hVals[i] + (int64_t)(1L << 25)) >> 26;
        } else {
            carry[i] = (hVals[i] + (int64_t)(1L << 24)) >> 25;
        }

        int index = (i + 1) % 10;
        if(index == 0){
            hVals[index] += carry[i] * 19;
        } else {
            hVals[index] += carry[i];
        }

        
        hVals[i] -= carry[i] * ((uint64_t) 1L << ((i%2)* 26 + 25*(1 - i%2)));
        
     h[i] = (int32_t) hVals[i];
   }
  

}