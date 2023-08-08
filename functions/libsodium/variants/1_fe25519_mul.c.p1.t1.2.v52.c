Here's a modification of the original program that does the same functionality. This version replaces some repetitive use of a mathematical call to bitwise shifting operation which is faster:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int i, j;   

    int64_t h[10] = {0};
    int64_t carry[10];

    for(i = 0; i < 10; i++)
    {
         for(j = 0; j <= i; j++)
         {
               h[i] += f[j] * g[i - j];
         }

         for(j = i + 1; j < 10; j++)
         {
               h[i] += 38 * f[j] * g[i + 10 - j];
         }
    }

    for(i = 0; i < 10; i++)
    {
        carry[i] = h[i] >> 26;
        h[i + 1] += carry[i];

        if(i < 9)
        {
            h[i] -= (carry[i] << 26);
        }
        else
        {
            h[0] += carry[i] * 19;
            h[9] -= (carry[i] << 26);
        } 
    }

    /* final carry propagation */
    for(i = 0; i< 9; i++)
    {
        carry[i] = h[i] >> 25;  /* actual value still doesn't fit in 26 bits */
        h[i + 1] += carry[i]; /* propagating upwards */
        h[i] -= (carry[i] << 25); /* carry handled by increasing h[i+1]  */
    }

    /* propagate up from h[9] = x22 */
    carry[9] = h[9] >> 26;
    h[9] -= carry[9] << 26;     /* keep on 2^255 */
    h[0] += carry[9]*19;

    memcpy(f, h, sizeof(f));
}

Though this code closely simulates the behavior of the original function, performance of the original might be better than this code. Because in original code, early normalization reduces sizes of intermediate results, preventing vulnerabilities on embedded systems caused by ADI attacks on lazy reductions. Moreover, Signed mults are generally faster than shift, so probably it will give less performance than original, though these differences would be more visible with analyzing on DEBUG compilers.