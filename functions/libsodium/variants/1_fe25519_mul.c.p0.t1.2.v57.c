fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_elements[10];
    int32_t g_elements[10];
    int32_t mul_factors[10] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2}; 

    for(int i = 0; i < 10; i++) {
        f_elements[i] = f[i];
        g_elements[i] = g[i];
    }

    for(int i = 1; i < 10; i++) {
      if(i%2 == 0) g_elements[i] *=  19;
      else f_elements[i] *= 2;
    }

    int64_t product[100];

    // calculate all products
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
           product[i * 10 + j] = ((int64_t)f_elements[i]) * ((int64_t)g_elements[j]);

    int64_t h_elements[10];

    for (int i = 0; i < 10; ++i) {
         h_elements[i] = 0;
         for (int j = 0; j <= i; ++j)
            h_elements[i] += product[j*10 + (i - j)];
         for (int j = i+1; j < 10; j++)
            h_elements[i] += product[j*10 + (i + 10 - j)] * mul_factors[i+10-j];
    }
    
    int64_t carry;

    // propagate the carry overflow
    h_elements[0] = (h_elements[0] + (int64_t)(1L << 25)) >> 26;
    h_elements[1] += h_elements[0];
    h_elements[0] *= ((uint64_t) 1L << 26);

    for(int index = 1; index < 10; ++index) {
       carry = (h_elements[index] + (int64_t)(1L << (25 + index%2))) >> (26 + index%2);
       h_elements[index] -= carry * ((uint64_t) 1L << (26 + index%2));
       h_elements[(index+1)%10] += carry;
    }

    for(int i = 0; i < 10; i++)
        h[i] = (int32_t) h_elements[i];
}