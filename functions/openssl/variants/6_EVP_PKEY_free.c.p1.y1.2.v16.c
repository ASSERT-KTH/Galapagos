1) Split large single conditionals into smaller steps:


void EVP_PKEY_free(EVP_PKEY *x)
{
    int i;

    if (x != NULL)
    {
        CRYPTO_DOWN_REF(&x->references, &i, x->lock);
        REF_PRINT_COUNT("EVP_PKEY", x);
        
        if (i <= 0) 
        {
            REF_ASSERT_ISNT(i < 0);
            evp_pkey_free_it(x);
            
            #ifndef FIPS_MODULE
            CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
            #endif
            
            CRYPTO_THREAD_lock_free(x->lock);

            #ifndef FIPS_MODULE
            sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
            #endif
            
            OPENSSL_free(x);       
        }
    }
    return;
}


2) Group semantic blocks in braces:


void EVP_PKEY_free(EVP_PKEY *x)
{
    int i;

    if (x != NULL)
    {
        {
            CRYPTO_DOWN_REF(&x->references, &i, x->lock);
            REF_PRINT_COUNT("EVP_PKEY", x);
        }
	flags
	current selected implementation
        if (i <= 0)
        {
            REF_ASSERT_ISNT(i < 0);
            {
                evp_pkey_free_it(x);

                #ifndef FIPS_MODULE
                {
                    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
                }
                #endif
                
                CRYPTO_THREAD_lock_free(x->lock);
            
                #ifndef FIPS_MODULE
                {
                    sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
                }
                #endif
                
                OPENSSL_free(x);
            }       
        }
    }
    return;
}


3) Flip the if conditional checks:


void EVP_PKEY_free(EVP_PKEY *x)
{
    int i;

    if (x == NULL)
    {
        return;
    }

    CRYPTO_DOWN_REF(&x->references, &i, x->lock);
    REF_PRINT_COUNT("EVP_PKEY", x);

    if (i <= 0)
    {
        return;
    }

    REF_ASSERT_ISNT(i < 0);
    evp_pkey_free_it(x);
  
    #ifndef FIPS_MODULE
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x->ex_data);
    #endif

    CRYPTO_THREAD_lock_free(x->lock);

    #ifndef FIPS_MODULE
    sk_X509_ATTRIBUTE_pop_free(x->attributes, X509_ATTRIBUTE_free);
    #endif

    OPENSSL_free(x);
}
