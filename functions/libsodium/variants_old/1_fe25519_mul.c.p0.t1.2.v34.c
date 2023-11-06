fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    struct index_tuple {
        int32_t f;
        int32_t g;
    };

    struct index_tuple pair[10];
    for (int i=0; i<10; ++i) {
        pair[i].f = f[i];
        pair[i].g = g[i]; 
    }

    int64_t fpair[10], gpair[10], reactions[225]; 
    for (int i=0; i<10; ++i) {  
        fpair[i] = 2 * abs(pair[i].f);  // Insure positive values with operation abs
        gpair[i] = 19 * pair[i].g;     
    }
    
    /* Create a new array reactions to store the products */
    int counter = 0;
    for (int i=0; i<10; ++i) {
        for (int j=0; j<10; ++j) {
            reactions[counter] = pair[i].f * (int64_t) pair[j].g;
            ++counter;
        }
    }

    int64_t resultset[10];  // Declare another array int64 for the results
    for (int i=0; i< 10; ++i) {
        /* Instead of shift and carry, keep the temporary results in
        * 64bits and do a single shift at the end.
        * Input is 32bit, so a cumulative sum cannot overflow 64bit. */
        resultset[i] = (reactions[i * i] +
                        reactions[9 + (i<<3)] - reactions[(5 * i + 7) % 225] +
                        reactions[38 + (i<<3)] - reactions[(8 * i + 2) % 225] +
                        reactions[4 + ((i<<4)-(i<<1))] - reactions[(9 * i + 112) % 225] +
                        reactions[38 + (i*(23 + (i<<2)))] + reactions[15 + (i*7)]) >>                                                                                                                               26;
    }
    
    /* Set the return values as needed */
    counter = 0;
    while (counter < 10)
    {
        h[counter] = (int32_t)resultset[counter];
        counter++;
    }
}