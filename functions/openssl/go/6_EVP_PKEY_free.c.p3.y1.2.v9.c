As Go and C are fundamentally different languages with each having different design paradigms, it's not possible to maintain the exact function signature. In particular, Go does not support pointer arithmetic like C does, many of the OpenSSL library calls in the original C function does not have direct mapping Go functions neither there is a direct built-in construct to support the reference count used in this function. But if a mapping function written in Go considering all these facts, the equivalent function would be:

go

import (
    "sync"
    "crypto"
)

type EvpPkey struct {
    references int
    lock       *sync.Mutex
    exData     []byte
    attributes []crypto.X509Attribute
}

func (x *EvpPkey) Free() {

    if x == nil {
        return
    }

    //Rather than lowering the pointer, we decrement the value due to go not able dump memory, evaluate x all together will be responsible for GC
    x.lock.Lock()
    x.references--
    i := x.references
    x.lock.Unlock()

    if i > 0 {
        return
    }

    if i < 0 {
        panic("Negative reference count!")
    }

    // evp_pkey_free_int() doesn't have an equivalent in Go.
    // Implementation would depend heavily on the details of the Go asymmetric key crypto-services to provided details which it abstracts in C.

    // crypto-functions not their straightforward equivalents exist in Go either.
    // You would instead have to use a combination of Go's x509 and crypto packages. 
    // Exact implementation would depending on details on input and parameters

    // x.lock would become nil when the x object becomes eligible for garbage collection.

    // Go garbage-collection mechanism does not require freeing of resources as in openssl or C

    // Unlike C, don't have to explicitly memory references in Go.
}

In here I try to mimic the behavior without calling conversion functions as most of the details(map structures details) for SSL Level encryption aren't disclosed. I would strongly suggest to use "crypto/tls" package for secure communications using SSL/TLS like secure protocols in GO. 

Go team (golang.org/x/crypto) provides well defined and maintained cryptography related interfaces suggesting to depend on standard API designs.

Further understanding of the provided code representation, In "EVP_PKEY_free", it first checks whether the given pointer is null, it locks and checks the reference count of the key object and if it's still positive, simply returns which means that the same key object is still in use elsewhere.

Afterward the LOCK operation, When the ref count has expired, it calls the function that actually frees all the things attached with the key in first place. The 'ex_data' and 'attributes' list is also being cleaned. 

At the end the memory allocated for sent given pointer is freed and assigned with NULL pointers after all (This is completely managed by Garbage collection system GO)\From higher-level, A usage/purpose-direction basis, Even though we implemented struct following Key structure/function in C but all these cryptographic tasks like generating/loading private/public Keys, loading certificates, signing/verifying messages, would usually be accomplished by above mentioned "crypto/tls" packages in GO anyway."

Please provide a map(conversion details)/details related to the overall problem-area/ concept of using/moving SSL encryption functionality/implementation from low -level to higher-level, definitely will help to provide custom/literal implementations In GO. It would be safe if each encryption scheme/service follows compliance, standards along side staying updated with the library packages as bugged, out-dated encryption could lead to different desecrates.