You can modify the function to have a "consistent behavior", where the same steps are applied for each group of f's.


fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_2[10], f_b[10];
    int multiplier_b[] = {38, 19, 1};
    int64_t output[10], carry[10] = {0};

    for (int i = 0; i < 10; i++){
       f_2[i]  = 2 * f[i];
       f_b[i] = multiplier_b[i % 3] * f[i];
    }

    for(int i=0; i<10; i++){
        for(int j=0;j<=i;j++){
            int carryFactor = j<j/2 ? 1 : 2;
            int bbFactor = j%3 == 0 ? 1 : 2;

            if(j==i)
                output[i] += f[j]*(int64_t)f[j]*carryFactor;
            
            if(i>j) 
                output[i] += f_2[j]*(int64_t)f[(i-j)]*carryFactor*bbFactor;
              
           //odd nums need minus j (Their own)
            if((i != j) && (i%2 != 0))
                output[i] -= f[j]*(int64_t)f[j]*carryFactor;
               
            output[i] += f_b[j]*(int64_t)f[(10+i-j)%10]*carryFactor;

        }
    }

    for(int i = 0;i<10;i++){

       carry[i % 10] = (output[i % 10] + 
                       (int64_t)(1L << (i % 2 == 0 ? 26 : 25) - 
                       (i % 2 == 0 ? 1 : 0))) 
                       >> (i % 2 == 0 ? 26 : 25);

       //final addition Part: Below conditions coverd
       output[(i+1)%10] += carry[i%10];
       output[i % 10] -= carry[i%10] * ((uint64_t) 1L << (i % 2 == 0 ? 26 : 25));

       h[i % 10] = (int32_t) output[i % 10];
    }
}

Above code maintains the logic of original while formally unroll the iterative steps into constant-length loop blocks. It works based on understanding of f0_sq faces one squaring step, f1_sq faces one linear combination more and f2_sq squares one less step but receives more linear combinations from others taken bb into account.