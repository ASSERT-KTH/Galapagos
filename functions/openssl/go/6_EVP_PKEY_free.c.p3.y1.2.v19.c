The existing C function cannot be rewritten in Go directly because Go doesn't inherently support reference counting like C, it's garbage collected and Go doesn't have OpenSSL APIs. We will require wrappers around OpenSSL APIs or equivalent libraries existing in Go world. You normally wouldn't see these raw pointer & references semantics in your typical Go code.

This is only a hypothetical and conceptual translation where parallel library/direct function replacement does not exist. 

Go
import (
    "sync"
    "crypto"
)

type EVP_PKEY struct {
    references int
    lock       sync.Mutex
    // Assuming ExData to be of string type, replace with appropriate type
    exData     string
    // Replace with attribute type (undefined here)
    attributes []X509_ATTRIBUTE
}

func EVP_PKEY_free(x *EVP_PKEY) {
    if x == nil {
        return
    }

    x.lock.Lock()
    references := &x.references
    *references -= 1
    i := *references
    x.lock.Unlock()

    // "REF_PRINT_COUNT" and "REF_ASSERT_ISNT" not translated as no equivalent exist in Go

    if i > 0 {
        return
    }

    // These OpenSSL/crypto library functions directly do not exist in Go
    // Parallel equivalent APIs would be required   -

    // evp_pkey_free_it(x)
    // CRYPTO_free_ex_data(CRYPTO_EX_INDEX_EVP_PKEY, x, &x.ex_data)

    // Manually free attributed elements; Garbage Collector will take care of x.
    for range x.attributes {
      // X509_ATTRIBUTE_free(e) , assuming X509_ATTRIBUTE_free is a hypothetical cleaning function for attribute type 
    }
    x.attributes = nil
    x.lock = sync.Mutex{}
}
