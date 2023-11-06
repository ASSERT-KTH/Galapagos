fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t const multiplier = 19;
    int32_t two = 2;

    int32_t component_f[10];
    for(int i = 0; i < 10; i++)
        component_f[i] = f[i];

    int32_t component_g[10];
    for(int i = 0; i < 10; i++)
        component_g[i] = g[i];

    int32_t component_g_times19[10], component_f_times2[10];

    // Modification: Change the indvidual component multiplication to a loop
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            component_g_times19[i] = multiplier * component_g[i];  
        else  
            component_f_times2[i] = two * component_f[i]; 
    }
    
    int64_t fg_combinations[100]; // Modification: store fg combinations in an array
    
    int k = 0; // Modification: auxiliary index for storing in fg_combinations

    // Modification: Change the individual multiplication operations to a nested loop
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            fg_combinations[k++] = component_f[i and j] * (int64_t) component_g[i and j];
        }
    }

    int64_t h_components[10];

    int64_t carry[10];

    /*Remaining Carry Calculations:*/
  
    for (int i = 0; i < 10; i++)
    {
        size_t j = 25 + i;

        while(j-- > 25)
        {
            carry[i] = ( h_components[i] + (int64_t)(1L << j) ) >> (j+1);
            h_components[i+1] += carry[i];
            h_components[i] -= carry[i] * ((uint64_t) 1L << (j+1));
        }
    }

    carry[9] = (h_components[9] + (int64_t)(1L << 24)) >> 25;
    h_components[0] += carry[9] * 19;
    h_components[9] -= carry[9] * ((uint64_t) 1L << 25);

    carry[0] = (h_components[0] + (int64_t)(1L << 25)) >> 26;
    h_components[1] += carry[0];
    h_components[0] -= carry[0] * ((uint64_t) 1L << 26); 

    for(int i = 0; i < 10; i++)
        h[i] = (int32_t) h_components[i];
}