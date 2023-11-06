Variant 1:


void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_values[10];
    
    for (int i = 0; i < 10; ++i)
    {
        f_values[i] = f[i];
    }

    int32_t f_mult_values[10];
    
    for (int i = 0; i < 10; ++i)
    {
        if (i == 5 || i == 7 || i == 9){
            f_mult_values[i] = 38 * f_values[i];
        } else if (i < 8){
            f_mult_values[i] =  2 * f_values[i];
        }
    }

    int64_t f_product_values[45];

    for (int i=0; i <10 ; ++i)
    {
        for (int j=0; j<10; ++j){
            if (i < j){
                f_product_values[i*10 + j] = f_mult_values[i] * (int64_t) f_values[j];
            } else {
                f_product_values[i*10 + j] = f_values[i] * (int64_t) f_values[j];
            }
        }
    }

    int64_t h_values[10] = {0};

    for (int i=0; i<10; ++i)
    {
       for (int j=0; j<10; ++j)
       {
           h_values[i] = f_product_values[i+j];
       }
    }

    // order for addition and subtraction in carry is very sensitive
    // Variance for steps can result in drastic changes in the end result
    int64_t carry[10];

    for (int i = 0; i < 10; ++i)
    {
        carry[i] = (h_values[i] + (int64_t) (1L << (25 + (i%2)))) >> (26 - (i%2));
        h_values[(i+1) % 10] += carry[i];
        h_values[i] -= carry[i] * ((uint64_t) 1L << (26 - (i%2)));
    }

    carry[0] = (h_values[0] * (int64_t)(1L << 25)) >> 26;
    h_values[1] += carry[0];
    h_values[0] -= carry[0] * ((uint64_t)1L << 26);

    for (int i = 0; i < 10; ++i)
    {
        h[i] = (int32_t) h_values[i];
    }
}


These variants assume that 'fe25519' is a typedef for a numerical array with 10 elements typed either as 'int32_t' or wrapper struct over such an array. The above transformation maintains a similar order of operation whilst reducing repeatability in original function.