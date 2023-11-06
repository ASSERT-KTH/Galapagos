
int BIO_free(BIO *a)
{

    int ret;

    if (!a)
        return 0;

    if (!(CRYPTO_DOWN_REF(&a->references, &ret, a->lock) > 0))
        return 0;

    REF_PRINT_COUNT("BIO", a);
    if (ret > 0)
        return 1;

    REF_ASSERT_ISNT(ret < 0);

    if (ret <= 0 && HAS_CALLBACK(a)) {
        if (bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL) <= 0)
            return 0;
    }

    if (a->method && a->method->destroy)
        a->method->destroy(a);

    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);

    CRYPTO_THREAD_lock_free(a->lock);

    OPENSSL_free(a);

    return 1;
}



int BIO_free(BIO *a)
{
    int ret = 0;

     if(NULL != a){
        
        if(CRYPTO_DOWN_REF(&a->references,&ret,a->lock)>0){
            
            REF_PRINT_COUNT("BIO",a);

            if( ret > 0 )
                return 1; 

            REF_ASSERT_ISNT( ret < 0 );

            if(HAS_CALLBACK(a)){

                  if((int)bio_call_callback(a,BIO_CB_FREE,NULL,0,0,0L,1L,NULL) > 0){
                    
                if(a->method && a->method->destroy)
                     a->method->destroy(a);  

                   }

            }        

            CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
            
            CRYPTO_THREAD_lock_free(a->lock);
            
            OPENSSL_free(a);
        
        }
      }

    return !(ret > 0);
}



int BIO_free(BIO *a)
{
    int ret = 0;

    do 
    {
        if (!a) break;

        if (CRYPTO_DOWN_REF(&a->references, &ret, a->lock) <= 0) break;

        REF_PRINT_COUNT("BIO", a);

        if (ret > 0) return 1;

        REF_ASSERT_ISNT(ret < 0);

        if (HAS_CALLBACK(a)) {

            ret = bio_call_callback(a, BIO_CB_FREE, NULL, 0, 0, 0L, 1L, NULL) <= 0;

           if (ret) break;
        }

        if (a->method && a->method->destroy)
             a->method->destroy(a);     

        CRYPTO_free_ex_data(CRYPTO_EX_INDEX_BIO, a, &a->ex_data);
        
        CRYPTO_THREAD_lock_free(a->lock);

        OPENSSL_free(a);

        ret = 1;

     } while(0);

    return ret;
}
