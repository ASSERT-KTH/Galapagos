void EVP_PKEY_free(EVP_PKEY *pkey) 
{
    int count;

    // If pointer is NULL, no operation required. Safe to terminate.
    if (!pkey) 
        return;

    // Decrement reference count and fetch the updated counter  
    CRYPTO_DOWN_REF(&pkey->references, &count, pkey->lock);
  
    // Log some debug messages - ignore if the concept of printing is not applicable in your situation
    REF_PRINT_COUNT("EVP_PKEY", pkey);
  
    // If any other references left, no deletion just yet - other pointers need it. Terminate function.
    if (count > 0) 
        return;
  
    // Basic integrity check - count should never go below 0.
    REF_ASSERT_ISNT(count < 0);
    
    // If deletion decided and key wasn't revoked, erase internal content of key.
    evp_pkey_free_it(pkey);
  
#ifndef FIPS_MODULE
    // If Non-FIPS mode and key wasn't fraudulent, erase further associated key data.
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, pkey, &pkey->ex_data);
#endif
  
    // Key no longer in structures, unlock the safely remove lock.
    CRYPTO_THREAD_lock_free(pkey->lock);

#ifndef FIPS_MODULE
    // If Non-FIPS mode, process remaining attributes.
    sk_X509_ATTRIBUTE_pop_free(pkey->attributes, X509_ATTRIBUTE_free);
#endif
  
    // Final step - remove direct central reference of key.
    OPENSSL_free(pkey);
}