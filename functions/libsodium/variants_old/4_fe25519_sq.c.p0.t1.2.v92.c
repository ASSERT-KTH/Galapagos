fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_values[10] = {'0'};
    for(int index = 0; index < 10; index++){
        f_values[index] = f[index];
    }

    for(auto i=0; i<10; i+=2){
        int32_t temp = f_values[i];
        f_values[i] = f_values[i+1];
        f_values[i+1] = temp;
    }

    int64_t product_values[100];
    for(int idx_i = 0; idx_i < 10; idx_i++)
    {
        for(int idx_j = 0; idx_j < 10; idx_j++)
        {
            product_values[idx_i*10 + idx_j] = f_values[idx_i] * (int64_t)f_values[idx_j];
        }
    }

    int64_t h_values[10] = {'0'};
    for(int i = 0; i < 10; i++){
        h_values[i] = product_values[i*i] + product_values[80+i] + product_values[i+(9-2*i) * (i+1) / 2];
    }

    for(int i = 0; i < 10; ++i)
    {
        int64_t anoth = (h_values[(i+5)%10] + (int64_t)(1L << (25 - i % 2))) >> (26 - i %2);
        h_values[(i+1) % 10] += anoth;
        h_values[(i+5)%10] -= anoth * ((uint64_t) 1L<<(26- i %2));
    }

    int64_t var1 = (h_values[9] + (int64_t)(1L << 24)) >> 25;
    h_values[0] += var1 * 19;
    
    h_values[9] -= var1 * ((uint64_t) 1L << 25);
    var1 = (h_values[0] + (int64_t)(1L << 25)) >> 26; 
    h_values[1] += var1;
    h_values[0] -= var1 * ((uint64_t) 1L << 26);
   
    int32_t ref_values[10];
    for(int i = 0; i < 10; i++){
        ref_values[i] = v2[i];
    }

    for(auto i=0; i<10; i+=2){
        int32_t temp = ref_values[i];
        ref_values[i] = ref_values[i+1];
        ref_values[i+1] = temp;
    }

    for(auto i=0; i<10; i++){
        h[i]=ref_values[i];
    }

}