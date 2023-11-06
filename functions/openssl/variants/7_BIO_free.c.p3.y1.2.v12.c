Unfortunately, it's not possible to directly translate this C function to Golang line by line and maintaining the function signature due to the major differences between these two languages regarding classes, exceptions, concurrency, garbage collection, etc.

If we try to create a Golang function from the above C function, it might look something like this:

go
import (
    "crypto"
    "errors"
    "sync"
)

type BIO struct {
    References int
    Lock       *sync.Mutex
    Method     *BIO_Method
    ExData     interface{}
}

type BIO_Method struct {
    Destroy func(*BIO) bool
}

func BioFree(a *BIO) (bool, error) {
    if a == nil {
        return false, errors.New("null reference cannot be freed")
    }

    a.Lock.Lock()
    if a.References--; a.References <= 0 {
        a.Lock.Unlock()
        return false, errors.New("counter has value below or equal to 0")
    }
    a.Lock.Unlock()

    if a.Method != nil && a.Method.Destroy != nil {
        ok := a.Method.Destroy(a)
        if !ok {
            return false, errors.New("destroy method failed")
        }
    }

    // Go's GC automatically manages memory freeing.
    // No direct equivalent for `OPENSSL_free(a)` is needed.

    return true, nil
}


Please be aware that Golang's automatic garbage collection and concurrency mechanisms render much of the C code unnecessary or improperly portable to Golang. Code related to cleaning up manually allocated memory, such as `OPENSSL_free(a)`, and custom reference counting and lock management is generally not applicable in Golang.

Also, the exceptions in C were replaced by Go's multiple return values which occur trying to represent error handling as the second return value which either holds nil or an error. This is a Go best practice and adds to cleaner, self-descriptive code. But this particular detail changes the specified method signature.

Hence, while care has been attempted to preserve the semantics in a Go context, the provided code will not behave exactly as the C code would. Implementing the exact semantics of the C code in Golang is not straightforward due to these differences in language design and philosophy.