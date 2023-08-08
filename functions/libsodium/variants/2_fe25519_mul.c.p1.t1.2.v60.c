fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;

    uint128_t f_elements[5];
    uint128_t g_elements[5];
    uint128_t f_percented[4];
    uint128_t results[5], r_fractioned[5];
    uint64_t  carries;
 
    for(int i = 0; i < 5; i++)
    {
        f_elements[i] = (uint128_t) f[i];
        g_elements[i] = (uint128_t) g[i];

        if(i != 0)
        {
            f_percented[i - 1] = 19ULL * f_elements[i];
        }
    }

    results[0] = f_elements[0] * g_elements[0] + f_percented[3] * g_elements[4] + f_percented[2] * g_elements[3] + f_percented[1] * g_elements[2] + f_percented[0] * g_elements[1];
    results[1] = f_elements[0] * g_elements[1] + f_elements[1] * g_elements[0] + f_percented[3] * g_elements[3] + f_percented[2] * g_elements[2] + f_percented[1] * g_elements[1] + f_percented[0] * g_elements[2];
    results[2] = f_elements[0] * g_elements[2] + f_elements[1] * g_elements[1] + f_elements[2] * g_elements[0] + f_percented[3] * g_elements[3] + f_percented[2] * g_elements[2] + f_percented[1] * g_elements[3];
    results[3] = f_elements[0] * g_elements[3] + f_elements[1] * g_elements[2] + f_elements[2] * g_elements[1] + f_elements[3] * g_elements[0] + f_percented[3] * g_elements[2] + f_percented[2] * g_elements[3];
    results[4] = f_elements[0] * g_elements[4] + f_elements[1] * g_elements[3] + f_elements[2] * g_elements[2] + f_elements[3] * g_elements[1] + f_elements[4] * g_elements[0] + f_percented[3] * g_elements[3];

    for(int i = 0; i < 5; i++)
    {
        r_fractioned[i] = ((uint64_t) results[i]) & mask;
        carries  = (uint64_t) (results[i] >> 51);

        if ((i + 1) != 5) 
        {
            results[i + 1] += carries;
        }
        else 
        {
            r_fractioned[0] += 19ULL * carries;
        }
    }

    carries = r_fractioned[4] >> 51;

    for(int i = 0; i < 5; i++)
    {
        r_fractioned[i] &= mask;

        if (i != 0) 
        {
            r_fractioned[i] += carries;
        }
        else 
        {
            r_fractioned[1] += carries;
        }
        
        carries = r_fractioned[i] >> 51;
    }

    for (int i = 0; i < 5; i++) 
    {
        h[i] = r_fractioned[i];
    }
}