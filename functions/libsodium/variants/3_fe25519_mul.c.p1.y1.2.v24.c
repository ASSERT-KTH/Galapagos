
void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_components[10];
    int32_t g_components[10];
    for(int i=0; i<10; i++){
        f_components[i] = f[i];
        g_components[i] = g[i]; //Storing the array elements f and g into f_components and g_components.
    }
     
    int64_t multiplicaton_constants[10]={f_components[0], 2*f_components[1], f_components[2], 2*f_components[3], f_components[4], 2*f_components[5], f_components[6], 2*f_components[7], f_components[8], 2*f_components[9]}; 
      
    int64_t f_i_trans_g_j[100];
    /* Implement pairs multiplication here */
    int m=0;
    for(int i=0; i<10; i++) {
        for(int j=0; j<=i; j++){
            if(i==j)
              f_i_trans_g_j[m] = multiplicaton_constants[i] * (int64_t) g_components[j];
            else if(j%2==0 && i%2==0)
              f_i_trans_g_j[m] = multiplicaton_constants[i] * (int64_t) g_components[j] * 19;//g_j's index is even.
            else
              f_i_trans_g_j[m] = multiplicaton_constants[i] * (int64_t) g_components[j];
            ++m;  
        }
    }
    int64_t h_components[10] = {0};
    int index_array[10][10] = {{0,18,28,38,48,58,68,78,88,98},{1,20,30,39,49,59,69,79,89,99} /* and so on till h9 combination proportionally*/ };

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            h_components[i] = h_components[i] + f_i_trans_g_j[j]; //Add corresponding proportional element values upto h9.
        }
    }
    int64_t carry[10];
    for(int i=0; i<10; i++){
      carry[i] = (h_components[i] + (int64_t)(1L << ((i%2 == 0)?25:24))) >> ((i%2 == 0)?26:25); //Applying for loop to allocate carry
      if(i<9) h_components[i+1] += carry[i];
      if(i==9) h_components[0] += carry[9] * 19;
      h_components[i] -= carry[i] * ((uint64_t) 1L << ((i%2 == 0)?26:25));
    }
    //copy adjusted h_components values into result `h`.
    for(int i=0; i<10; i++){
        h[i]=(int32_t)(h_components[i]);
    }
}
