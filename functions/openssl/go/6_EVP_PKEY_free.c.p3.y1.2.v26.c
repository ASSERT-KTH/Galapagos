There are inherent differences between C and Go, especially pertaining to memory management and thread safety. Both languages are compiled and statically typed, but while C requires explicit object lifecycle management given a determinate memory location (pointer') for most variable values, Go utilizes garbage collection which abstracts away much of the intricate. Given these distinctions, here's how we might convert the aforementioned C code to Go, noting that there is no exact counterpart for numerous C concepts and OpenSSL-specific functions:

go
import (
    "sync"
)

type EVP_PKEY struct {
    references int
    lock       *sync.Mutex
    ex_data    interface{}
    attributes []X509_ATTRIBUTE
}

func EVP_PKEY_free(x *EVP_PKEY) {
    if x == nil {
        return
    }

    x.lock.Lock()
    x.references--
    i := x.references
    x.lock.Unlock()

    if i > 0 {
        return
    }

    if !(i < 0) {
        // assuming that evp_pkey_free_it(x) 
        // is a method to deallocate inner struct elements
        x.ex_data = nil
        x.attributes = nil
    }

    x = nil
}

In the provided Go representation, we use EVPN_PKEY as a struct with fields that are similar to the C EVPN_PKEY struct (according to the context usage in the original C function). Please note that there's no exact thread safety concept in Go, but protected data mutation is exemplified via a Go mutex. Some OpenSSL functions were replaced by Go-specific counterparts, e.g., memory allocation and de-allocation is done by the garbage collection mechanism automatically.
Use and function of X509_ATTRIBUTE array unclear under given context, hence the resulting golang treatment an educated assumption
A simplication instead CRYPTO_free_ex_data() is that Go's garbage collection handles memory destructuring, hence releasing object reference will destruct allocated memory for the object.