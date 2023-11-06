Variant 1:

void EVP_PKEY_free(EVP_PKEY *x)
{
    int critical_flag = 0; 

    if (x) 
     {
        CRYPTO_DOWN_REF(&x->references, &critical_flag, x->lock);

        if(!critical_flag) 
         {
            if(critical_flag >= 0)
             {
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
            REF_ASSERT_ISNT(critical_flag < 0);
         }
        REF_PRINT_COUNT("EVP_PKEY", x);
    }
}     
 
Variant 2:

void EVP_PKEY_free(EVP_PKEY *handler)
{
    int idx;

    if (handler != NULL)
    {
        CRYPTO_DOWN_REF(&handler->references, &idx, handler->lock);
        if (idx == 0) 
        {
            REF_ASSERT_ISNT(idx < 0);
            evp_pkey_free_it(handler);

#ifndef FIPS_MODULE
            CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, handler, &handler->ex_data);
#endif
            CRYPTO_THREAD_lock_free(handler->lock);

#ifndef FIPS_MODULE
            sk_X509_ATTRIBUTE_pop_free(handler->attributes, X509_ATTRIBUTE_free);
#endif
            OPENSSL_free(handler);
        }
        REF_PRINT_COUNT("EVP_PKEY", handler);
    }
}
 

Variant 3:

void EVP_PKEY_free(EVP_PKEY *p)
{
    int j;

    if (p)
    { 
        CRYPTO_DOWN_REF(&p->references, &j, p->lock);

        if(j == 0)
        {
            evp_pkey_free_it(p);
#ifndef FIPS_MODULE
            CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, p, &p->ex_data);
#endif
            CRYPTO_THREAD_lock_free(p->lock);
#ifndef FIPS_MODULE
            sk_X509_ATTRIBUTE_pop_free(p->attributes, X509_ATTRIBUTE_free);
#endif     
            OPENSSL_free(p);
        }
        REF_ASSERT_ISNT(j < 0);
        REF_PRINT_COUNT("EVP_PKEY", p);       
    }
}
