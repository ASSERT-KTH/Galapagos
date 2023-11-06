Translating the provided C code into Go would be entirely reliant on the underlying OpenSSL C libraries that this function depends on, it wouldn't be exactly possible or functional. 

However, for the purpose of illustration on implementing parallel conditions (NULL checks or conditionalized component freeing) in Go, we will use the Golang OpenSSL wrapper `crypto/tls`, but keep in mind it would not make much sense comparing to the original in terms of functionality.

Go
func EVP_PKEY_free(x *tls.Certificate) {
    if x == nil {
        return
    }

    // Assuming the purpose of Ref counts in OpenSSL are for garbage collection in Go, 
    // Thus we can simply set the variable pointed by x to nil allowing Go's GC to dealloc
    x = nil
    return
}


In Golang, we don't have to worry about releasing memory as we would need in C because there is a garbage collector which automatically reclaims memory that is no longer being referenced. The garbage collector prevents an application from holding onto more memory than it needs, while at the same time ensuring that all data remains protected until no references to the data remain.
In the example above, by setting x to nil, it means it won't reference the `tls.Certificate` anymore, and Hence Go's GC will deallocate / reclaim the memory.
Please refer to capabilities of underlying libraries like OpenSSL for functionalities of copy, free, lock, etc., as this function performs beyond a standard language conversion. 

However, applying the same instructions equivalent as Go in the above function may require creation ou auxiliary/helper function contrary to your instructions. As traditional PKI operations appears to be like freeing memory, locking and conditional checks which is not all applicable directly to the Go given Go's automatic garbage collection. and thus it will not completely ultimately necessary in Go(Golang). Hence it will not be a perfect translation to convert such a code, from one language like C to Go, as both of these language use distinct convention to handle System resources like memory.