Sorry, but it's impossible to translate this C code precisely to Go, because this code utilizes some OpenSSL library features and references, which are not available in Go. Go uses its own crypto libraries that are built-in and these OpenSSL elements will not directly map over. Also, map over pointer arithmetic from C to Go is tricky since Go doesn't offer the same level of pointer manipulation as done in C. 

If in case, your ultimate goal is to free any OpenSSL “BIO” objects then you may do so by utilizing CGO (C bindings for Go) which lets Go programs call C code. Below is not a direct translation of your function but it captures essence of it in below Go function: 

golang
/*
#cgo LDFLAGS: -lcrypto
#include <openssl/bio.h>
*/
import "C"

func BioFree(b *C.BIO) int {
    if b == nil {
        return 0
    }

    result := C.BIO_free(b)

    return int(result)
}

As per documentation of OpenSSL, `BIO_free` frees up a single BIO. `BIO_free` function automatically calls method-specific structure free routines if necessary so we don’t have complete control over it as mentioned in C-function in your query. Returned value from `BIO_free` function is `1` on success and `0` otherwise. It is necessary to understand that Go’s garbage collection is abstract so we cannot usually necessitate instance cleanup processes in semantic Go Code.