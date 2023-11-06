Unfortunately, Go does not natively support the OpenSSL library and hence OpenSSL's 'BIGNUM' structure, 'BN_get_flags' and 'OPENSSL_free' functions aren't available. But to show the concept of how you should use Go, you can write following Go code, which ideologically implements the similar functionality:

go
func BnFree(a *big.Int) {
    if a == nil {
        return
    }

    a = new(big.Int)
}


Please note that Go does a very good job with garbage collection, and it happens automatically. You usually don't and can't explicitly free allocated memory. Memory would be collected by the garbage collector when there are no more references to the memory. But this example indicates how to make sure there are no more references to the memory object and hence make it ready for garbage collection.