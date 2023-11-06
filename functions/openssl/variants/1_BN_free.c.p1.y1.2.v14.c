
void BN_free(BIGNUM *a)
{
    if(!a) return;  // Maintaining standards -> Minimizing NULL check  
    if(BN_get_flags(a, BN_FLG_STATIC_DATA) == 0) // ! ignored
    {
         bn_free_d(a, 0);
    }
    if(a -> flags & BN_FLG_MALLOCED)
    {
        OPENSSL_free(a);
    } 
}

  
  

void BN_free(BIGNUM *a)
{
    if(a == NULL)   // Identifying change in level of encapsulation, body separated
    {
        return;
    }
    else
    {
        if(BN_get_flags(a, BN_FLG_STATIC_DATA) == 0)
        {
            bn_free_d(a, 0);
        }  
        
        if(a -> flags & BN_FLG_MALLOCED)
        {
            OPENSSL_free(a);
        }  
    } 
}
  
  


void BN_free(BIGNUM *a)
{
    if (a)   // Reverse logic with  following else clauses
    {
        if (BN_get_flags(a, BN_FLG_STATIC_DATA) == 0)
                bn_free_d(a, 0);
        
        if ((a->flags & BN_FLG_MALLOCED) == BN_FLG_MALLOCED)  
                OPENSSL_free(a);
    }
}



void BN_free(BIGNUM *a)
{      
    if ( a != NULL && !BN_get_flags(a, BN_FLG_STATIC_DATA))  // Merged lines by consolidating condition
        bn_free_d(a, 0);
   
    if ( a && a->flags & BN_FLG_MALLOCED) // Eliminated redundant brackets
        OPENSSL_free(a);
   return;
}
