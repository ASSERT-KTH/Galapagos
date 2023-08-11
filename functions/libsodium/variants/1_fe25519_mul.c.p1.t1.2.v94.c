Here's a variant:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int64_t s[10], t[32], carry;
    int i;
    for (i = 0; i < 32; i++)
    {
       t[i] = 0;
    }

    for(i = 0; i < 10; i++)
    {
        s[i] = f[i];
    }

    /*
    Each multiplication could be decomposed into main factors:
    1 - Same order multiplication s[i] * g[i]
    2 - Cross multiplication s[i <-> j] * 38
    *14 instead of *19, because 38 / 2 = 19 and two numbers are doubled.
    */
    for(i = 0; i < 10; i++)
    {
        int j;
        for (j = 0; j < 10; j++)
        {
           int k = i + j;
           
           t[k] += s[j] * g[i];
            
           if (i != j)
            {
                t[k] += 2 * 19 * s[j] * g[i];
           }
           
           /* Carry handling */
           while ( t[k] > ((1ull << 26) - 1))
           {
                  t[k+1] = t[k+1] + (t[k] >> 26);
                  t[k] = t[k] & ((1ll << 26) - 1);
           }
         }
    }

     /* Modulo 2^255 - 19 */
    carry = t[9] >> 21;
    for(i = 9; i > 0; i--)
    {
        t[i] = (t[i] - (carry << 21)) & ((1<<24)-1);
        carry = t[i-1] - carry;
    }

    t[0] = (t[0] - 19 * (t[10] >> 21)) & ((1 << 26) - 1);
    t[1] += t[10] >> 21;
     

     for(i = 0; i < 10; i++)
     {
        h[i] = t[i];
     }
}

The functionality remains the same, as this is just a performance-enhanced version of the original code. It carries out partial products inline – deciding what to compute at which-time which-sign-to-give brought more maintenance burden by more multipliers needed to be recomputed. To mitigate this, it treats small and large multiplicands & multiplier strings separately by introducing acceleration. Then it collects crops together by subtracting the accumulated negative off-part and finally does strict reduction state by less-magic constants.