void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t doubleValues[10], by38Values[5];
    int64_t products[45], carry[10], squaresAndProducts[10];

    for (int i = 0, j = 0; i < 10; i++) 
    {
        doubleValues[i] = 2 * f[i];
        if (i < 5) 
        {
            by38Values[i] = 38 * f[i+5];
            products[j++] = f[i] * (int64_t) (f[i]*2);
            products[j++] = doubleValues[i] * (int64_t) by38Values[i];
        }
        else
        {
          products[j++] = f[i] * (int64_t) (f[i]*2);
        }
    }

    squaresAndProducts[0] = products[0] + products[39] + products[36] + products[33] + products[28] + products[20];
    squaresAndProducts[1] = doubleValues[0] * (int64_t) f[1] + products[40] + products[37] + products[30] + by38Values[1] ;
    squaresAndProducts[2] = products[1] + products[40] + products[38] + products[31] + by38Values[2] + f[6] * 19LL;
    squaresAndProducts[3] = doubleValues[0] * (int64_t) f[3] + doubleValues[1] * (int64_t)f[2] + products[41] + by38Values[3] ;
    squaresAndProducts[4] = products[2] + products[42] + products[39] + products[34] + products[25] + (f[7] * 38LL);
    squaresAndProducts[5] = doubleValues[0] * (int64_t) f[5] + doubleValues[1] * (int64_t)f[4] + doubleValues[2] * (int64_t)f[3] + by38Values[4] ;
    squaresAndProducts[6] = products[3] + products[43] + products[40] + products[35] + products[26] + (f[8] * 19LL);
    squaresAndProducts[7] = doubleValues[0] * (int64_t) f[7] + doubleValues[1] * (int64_t)f[6] + doubleValues[2] * (int64_t)f[5] + doubleValues[3] * (int64_t)f[4] + (f[8]*19LL) ;
    squaresAndProducts[8] = products[4] + products[44] + products[41] + products[36] + f[4] * (int64_t) f[4] + f[9] * 38LL;
    squaresAndProducts[9] = doubleValues[0] * (int64_t) f[9] + doubleValues[1] * (int64_t)f[8] + doubleValues[2] * (int64_t)f[7]+ doubleValues[3] * (int64_t)f[6] + doubleValues[4] * (int64_t)f[5] ;

    carry[0] = (squaresAndProducts[0] + (int64_t)(1L << 25)) >> 26; squaresAndProducts[1] += carry[0]; squaresAndProducts[0] -= carry[0] * ((uint64_t) 1L << 26);
    carry[4] = (squaresAndProducts[4] + (int64_t)(1L << 25)) >> 26; squaresAndProducts[5] += carry[4]; squaresAndProducts[4] -= carry[4] * ((uint64_t) 1L << 26);

    carry[1] = (squaresAndProducts[1] + (int64_t)(1L << 24)) >> 25; squaresAndProducts[2] += carry[1]; squaresAndProducts[1] -= carry[1] * ((uint64_t) 1L << 25);
    carry[5] = (squaresAndProducts[5] + (int64_t)(1L << 24)) >> 25; squaresAndProducts[6] += carry[5]; squaresAndProducts[5] -= carry[5] * ((uint64_t) 1L << 25);

    carry[2] = (squaresAndProducts[2] + (int64_t)(1L << 25)) >> 26; squaresAndProducts[3] += carry[2]; squaresAndProducts[2] -= carry[2] * ((uint64_t) 1L << 26);
    carry[6] = (squaresAndProducts[6] + (int64_t)(1L << 25)) >> 26; squaresAndProducts[7] += carry[6]; squaresAndProducts[6] -= carry[6] * ((uint64_t) 1L << 26);

    carry[3] = (squaresAndProducts[3] + (int64_t)(1L << 24)) >> 25; squaresAndProducts[4] += carry[3]; squaresAndProducts[3] -= carry[3] * ((uint64_t) 1L << 25);
    carry[7] = (squaresAndProducts[7] + (int64_t)(1L << 24)) >> 25; squaresAndProducts[8] += carry[7]; squaresAndProducts[7] -= carry[7] * ((uint64_t) 1L << 25);

    carry[4] = (squaresAndProducts[4] + (int64_t)(1L << 25)) >> 26; squaresAndProducts[5] += carry[4]; squaresAndProducts[4] -= carry[4] * ((uint64_t) 1L << 26);
    carry[8] = (squaresAndProducts[8] + (int64_t)(1L << 25)) >> 26; squaresAndProducts[9] += carry[8]; squaresAndProducts[8] -= carry[8] * ((uint64_t) 1L << 26);

    carry[9] = (squaresAndProducts[9] + (int64_t)(1L << 24)) >> 25; squaresAndProducts[0] += carry[9] * 19; squaresAndProducts[9] -= carry[9] * ((uint64_t) 1L << 25);
    carry[0] = (squaresAndProducts[0] + (int64_t)(1L << 25)) >> 26; squaresAndProducts[1] += carry[0]; squaresAndProducts[0] -= carry[0] * ((uint64_t) 1L << 26);

    for (int i = 0; i < 10; i++) h[i] = (int32_t)squaresAndProducts[i];
}
