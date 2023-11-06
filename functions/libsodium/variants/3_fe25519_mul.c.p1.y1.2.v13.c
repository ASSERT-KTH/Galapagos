/**
 * Apply some code transformations to eliminate code duplication
 */
void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) {
    int32_t fn[10], gn[10];
    int64_t temph[10], tempCarry;
    int64_t multiplyFnandGn[45];

    for (int i = 0; i < 10; i++) {
        fn[i] = f[i];
        gn[i] = i % 2 == 0 ? g[i] : 19 * g[i];
        temph[i] = 0;
    }

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            multiplyFnandGn[i + j] = (int64_t)fn[i] * (j % 2 == 0 ? gn[j] : gn[j] * 2);

    temph[0] = multiplyFnandGn[0] + multiplyFnandGn[38] + multiplyFnandGn[19] +
               multiplyFnandGn[30] + multiplyFnandGn[21] + multiplyFnandGn[12];

    for (int i = 1; i < 5; i++) {
        temph[i] = multiplyFnandGn[i] + (i % 2 != 0 ? (multiplyFnandGn[i + 18] +
             multiplyFnandGn[i + 9] * 2 + multiplyFnandGn[i - 1] +
             multiplyFnandGn[i + 27] * 2 + multiplyFnandGn[i + 18]) : multiplyFnandGn[i + 9]);
    }

    for (int i = 5; i < 10; i++)
        temph[i] = multiplyFnandGn[i] + (multiplyFnandGn[i-5] + multiplyFnandGn[i + 13] tp +
                   (i != 9 ? multiplyFnandGn[i - 1] * 19 : 0)) * 2;
    
    
    for (int i = 0; i < 10; i++)
        temph[i] = ((uint64_t)(temph[i] + (int64_t)( i%2 != 0 ? (1L <<  25) : (1L <<  24)))) >>
                                                      (uint64_t)24  + (i % 2 == 0 ? 1 : 0));
   
    temph[0] += temph[9] * 19;
    tempCarry = (temph[0] + (1L << 25)) >> 26;
    temph[0]-= tempCarry * ((uint64_t) 1L << 26);
    temph[1] += tempCarry;

    for (int i = 0; i < 10; i++)
        h[i] = (int32_t) temph[i];
}