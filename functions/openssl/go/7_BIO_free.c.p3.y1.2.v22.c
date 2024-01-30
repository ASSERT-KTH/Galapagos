In Go, there is no direct way to translate C concepts such as pointers, manual memory management (like `OPENSSL_free()`), or custom deletion methods (like `a->method->destroy()`). Below is an attempted rough translation, which assume some Go structs and package methods that would mimic the behavior of the original C code:

go
import (
    "some/openSSL/package"
    "some/custom/Error/Handle/package"
    "some/other/necessary/package"
)

func BIOFree(a *BIO) int {
    if a == nil {
        return 0
    }

    ret, err := openSSLpackage.DownRef(&a.references, a.lock)
    HandleError.Assert(err)  // Assuming this behaves like REF_ASSERT_ISNT()
    if ret <= 0 {
        return 0
    }

    fmt.Printf("BIO: %v\n", a)  // Assume this acts as REF_PRINT_COUNT("BIO", a)
    if ret > 0 {
        return 1
    }

    if a.Callback() {   // Assume a has an associated boolean method Callback() in Go 
        ret = BioCallCallback(a, "BIO_CB_FREE", nil, 0, 0, 0, 1, nil)
        if ret <= 0 {
            return 0
        }
    }

    if a.method != nil && a.method.destroy != nil {
        a.method.destroy()
    }

    openSSLpackage.FreeExData(openSSLpackage.EX_INDEX_BIO, a, &a.exData)

    otherNecessaryPackage.Unlock(a.lock)

    openSSLpackage.Free(a)

    return 1
}


In the above translation,

- struct member access (`obj->field`) is replaced by Go's struct member access (`obj.field`).
- calls to functions from packages are assumed to exist and operate similarly to how they did in C.
- features of C not typically found in Go, like custom memory management and custom destructor functions/callbacks, are made into function/method calls.
- The replacement for the C `print_ref_count` macro, `fmt.Printf("BIO: %v\n", a)`, is used to logs to standard Out. ValueError/asserts exist in many libraries and has been picked as per one of those.
   
The above Go reference function is based on quite a few assumptions as described, if there is more specific requirement or implementation exist, changes needs to be done accordingly.