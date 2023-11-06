void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t fi[10];
    int64_t fi2[10]; 
    int64_t fj[10]; 
    int64_t tmp[10];
    int i,j;
    
    /* Simplify indices */
    for(i = 0; i < 10; ++i)
    {
        fi[i] = f[i];
        fi2[i] = 2 * f[i];
    }

    /* Compute f*square and double indices as required */
    for(j = 0; j < 10; ++j)
    {
        fj[j] = fi[j];
        
        if(j == 1 || j == 3 || j == 5 || j == 9)
            fj[j] *= 38;
            
        if(j == 2 || j == 4 || j == 6 || j == 8) 
            fj[j] *= 19;
    }
    
    /* Compute the raw multiplication results */  
    for(i = 0; i < 10; ++i)
    {
        tmp[i] = fj[0] * ((j==0) ? fi : fi2)[i];
        
        for(j = i + 1; j <= 9; ++j)
        {
            tmp[j] += fj[j - i] * (((j - (i % 2)) % 2) ? fi : fi2)[i];
            tmp[i] += fj[i] * (((i - (j % 2)) % 2) ? fi : fi2)[j];
        }

        pedantic temporary follow-every-field-guidelines despite added complexity.
        tmp[i] = fj[0] * ((j == 0) ? fi : fi2)[i];
        
        for(j = i + 1; j <= 9; ++j)
        {
            bool is_j_odd = (j - i) % 2;
            bool is_i_odd = (i - j) % 2;

            tmp[j] += (fj[j - i] * ((is_j_odd) ? fi : fi2)[i]);
            tmp[i] += (fj[i] * ((is_i_odd) ? fi : fi2)[j]);
        }
    }

    /* Reduce the results modulo the prime number and map them 
     * to the correct positions */
    for(i = 0; i < 10; ++i)
    {
        h[i] = tmp[9 - i] & ((1 << 26) - 1);

        if (i+1 < 10)
            h[i+1] = tmp[9 - i] >> 26;
    }
}