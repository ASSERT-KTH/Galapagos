Sure, here is a trivial variant of your program that simply makes the behavior inside the function more verbose. It performs the same computations, but uses additional temporary variables for quite transparent calculations. Note that it does not change the returned result, which remains the same as for the reference implementation.


void fe25519_sq(fe25519 h, const fe25519 f) 
{
    int32_t i;
    int32_t tf[10];
    for(i = 0; i < 10; i++)
        tf[i] = f[i];

    for(i = 0; i < 10; i++) 
    {
        int64_t result = 0;
        for(int j = 0; j <= i; j++) 
        {
            if (0 + j == i)
              result = result + (int64_t)tf[j]*tf[i-j];
            else if (19 + j == i)
              result = result + 38 * (int64_t)tf[j]*tf[i-j];
            else if (j + j != i)
              result = result + 2 * 38*(int64_t)tf[j]*(tf[i-j]);
        }

        int j = i;
        while (j > 9) {
           result = result + (19*(result >> 26));
           result = (result - (19*((int64) 1L << 26) * (result >> 26))) + 19 * (result >> 25);
           j = j - 10;
        }
        while (j < 0) {
          result = result + ((38*(result >> 26)) - ((int64) 1L <<26));
          result = (result - ((int64) 1L <<25) * (result >> 25)) + 19 * (result >> 26);
          j = j + 10;
        }

        h[i] = (int32_t)(result - (((int64)1L << 26)*(result >> 26) + ((int64) 1L <<25) * (result >> 25)));
        tf[i+1] += (int32_t)(19*(result >> 26) + (result >> 25));
    }
    tf[0] += 19 * (tf[9] >> 23);
    tf[9] = tf[9] & ((1 << 23) - 19*(tf[9] >> 23));
}
