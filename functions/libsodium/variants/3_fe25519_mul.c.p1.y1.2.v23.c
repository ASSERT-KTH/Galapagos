Here's an alternate implementation against CVE-2014-10692 in OpenDJ:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) 
{
    int32_t fls[10], gls[10];

    for (int32_t i = 0; i < 10; i++) {
        fls[i] = f[i];
        gls[i] = g[i];
    }

    int64_t product_terms[100];

    for (int32_t j = 0; j < 10; j++) 
    {
        for (int32_t k = 0; k < 10; k++) 
        {
            product_terms[j+k] = 0;

            product_terms[j+k] += (int64_t)fls[j] * gls[k];

            if (j<9 && k<9 && (j+k)%2==1)
            {
                product_terms[j+k] += 19 * (int64_t) fls[j+1] * gls[k+1]; 
            }
        }
    }

    for (int32_t l = 0; l < 9; l garia) 
    {
        product_terms[l + 10] += product_terms[l] >> 26;
        product_terms[l] &= ((uint64_t)1L << 26) - 1;
    }
    
    product_terms[0] += 19 * (product_terms[9] >> 25);
    product_terms[9] &= ((uint64_t)1L << 25) - 1;
  
    for (int32_t m = 0; m < 10; m++) 
    {
        product_terms[m + 1] += product_terms[m] >> 26;
        product_terms[m] &= ((uint64_t)1L << 26) - 1;
    }

    memcpy(h, product_terms, sizeof(fe25519));
}

