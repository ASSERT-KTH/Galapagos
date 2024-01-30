As we try to convert the C code to Go, certain OpenSSL specific elements of the C code don't translate to Go as there're no equivalent in standard Go libraries. That said, in case where Go doesn't have a direct analog, behaviors can usually be replicated using other techniques or libraries, but doing so usually brings unnecessary complexity.

The main idea should be about checking if the pointer x is not null, and if so, running methods/functions based upon variables within x. 

Below is an approximate structure - a skeleton you might say, because this will only concentrate on Object-Oriented usage of Go rather than cryptography that the initial code uses.

Golang:
go
type EVP_PKEY struct {
    References int
    Lock       sync.Mutex
    ExData     int
    Attributes []X509_ATTRIBUTE
}

type X509_ATTRIBUTE struct {
}

func X509_ATTRIBUTE_free(X509_ATTRIBUTE) {
    // define your function's body here
}

func (*x *EVP_PKEY) EVP_PKEY_free() {
    if x == nil {
        return
    }
    x.Lock.Lock()
    x.References--
    i := x.References
    x.Lock.Unlock()

    if i > 0 {
        return
    }
    if i < 0 {
        panic("i is less than 0")
    }
    // define evp_pkey_free_it whit the USAGE on your cryptographic frameworks
    CRYPTO_free_ex_data(x.ExData, x)
    for _, attr := range x.Attributes {
        X509_ATTRIBUTE_free(attr)
    }
}

Assuming that `X509_ATTRIBUTE` and `CRYPTO_free_ex_data` operate just on simple integers doesn't make justice to them, a true translation is complex because it would require knowledge of OpenSSL activity and its equivalent cryptography framework in Go, AND also of multi-thread duties needed due cryptography's calculation. They are specific to C/OpenSSL and translating them into Go would probably require usage a cryptography package which needs specifics standards than OpenSSL use. Also, a memory call, like C `OPENSSL_free(x)`, is not dealt with manually within garbage-collected Go. English