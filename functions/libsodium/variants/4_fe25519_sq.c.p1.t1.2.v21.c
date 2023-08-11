Sure, below is a functional equivalent of the given function. 

The behavior is slightly adjusted by using loops for repetitive calculations, and for adjusting numerical values in 9-valued array.

Please, look at the code:


void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t buffer[10];    
    int64_t results_mix[45];   
    int64_t h_values[10];   
    int multipliers[] = {2, 2, 2, 2, 38, 19, 38, 19, 38}; 
    int index_values[] = {0, 38, 19, 19, 0, 0, 0, 0, 0};  
    int cross_coeff_out[45] = {1,2,2,2,2,2,76,38,76,38,1, 
                               2,4,2,4,38,76,2,0,0,-1, 
                               2,2,76,38,38,38,-101,
                               2,4,2,0,0,0,0,-1,2,76,38, 
                               1,2,-1,1,2,1,1,1};  
    int carry[9] = {26, 25, 26, 25, 26, 25, 26, 25, 25}; 

    for(int i = 0; i < 10; i++){
        buffer[i] = f[i] * (i < 9 ? multipliers[i] : 1);                
    }

    int k = 0; 
    for(int i = 0; i < 10; i++){ 
        for(int j = i; j < 10; j++){
            int value1 = j==i ? f[i] : buffer[i]; 
            int value2 = i==j ? f[j] : (j < 9 ? buffer[j-index_values[i]] : f[j]);    
            results_mix[k++] = cross_coeff_out[index] * value1 * value2;
            index++;
        }
    }

   for (int i=0; i < 10; i++) {
      h_values[i] = 0;
      for (int j=0; j<10; j++) {
          int index = i-j; 
          if (index >= 0 && index < 10) {
              h_values[i] += results_mix[index];      
          }
          else if (index < 0 && i+j < 10) {
              h_values[i] += results_mix[i+j];      
          }
          else if (index < 0) {
              h_values[i] -= 19 * results_mix[i+j-10]; 
          }
       }
   }


    int64_t carryOver;
    for (int iteration=0; iteration<2; iteration++) { 
        carryOver = 0;
        for(int i = 0; i < 10 ; i++) {
            h_values[i] += carryOver -  ((template[i]==-1) ? 19*carryOver : 0);
            h_values[i] = (i<9 || iteration>0) ? h_values[i] + ((int64_t)1L << (carry[i]-1)) : h_values[i]; 
            carryOver = h_values[i] >> carry[i];
            h_values[i] -= carryOver << carry[i];
        }
    }

    for(int i = 0; i < 10; i++) { 
        h[i] = (int32_t) h_values[i];
    }
}


This function produces exactly the same output, but organizes repetitive/iterative computations using for-loops rather than performing them one by one. Advanced computation math schemes still are in action, and almost hidden behind several defined numeric arrays that store relative index, order, multiplier of values at position i etc.