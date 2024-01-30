Unfortunately, we can't create semantically equivalent Go code without knowing the underlying types and implementations of types, functions and macros utilized within provided C function, however this code explains how to make wrapping and mapping to underlying "C" syntax using cgo interface.

Below is C function mapped to "C" syntax and wrapped with pure Go function providing similar usage for end users.

go
package main

/*
 #include <openssl/evp.h>
 #include <openssl/crypto.h>

 // related imports ...

 void Go_EVP_PKEY_free(EVP_PKEY *x) {
     int i;

     if (x == NULL)
         return;

     CRYPTO_DOWN_REF(&x->references, &i, x->lock);
     REF_PRINT_COUNT("EVP_PKEY", x);

     if (i > 0)
         return;

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
*/
import "C"

// CAUTION: This Go function is provided as an adaptation from C to Go 
//          NOT as a semantically equivalent implementation directly in Go language.
func EVPPKEYFree(x *C.EVP_PKEY) {
    C.Go_EVP_PKEY_free(x)
}

It's worth when using cgo, to note that the function "EVP_PKEY_free()" would free allocated memory as per openssl equivalent logic in internal execution within "C' syntax. But be cautious that further operation after calling this function on "EVP_PKEY" might cause undefined behavior (most probably a crash). Also FIPS_MODULE defined macros and links are missing which breifly implies additional implementatin needed depends on business needs.

Note this isn't standalone Go version of "EVP_PKEY_free()", instead it's just a kind wrapper calling underlying mapped "C" function, A duplicate/auxiliary function used when efficient "C to Go" mappings are necessary and existing "C" codebase is sufficient and already well tested.
  
In Real World: In real practice security concerns are sdnside linuccient application a direct Go semantic implementation highly depends on requirements and it would be allocation/release related mappings for visibility and deterministic model specific to domain and implementation optimizations. Hence gave more common practice way for existing OpenSSL/crypt based libs wrapping. Sdnside Implementation would need more specific portions transforming depending on detailed internals visibility clarifications about APIs mentioned above ; For Go, Usually cipher suites packages and APIs of stdlib solves most of issues in this territory in semantically similar way aligning to C's EVP programming aspects.