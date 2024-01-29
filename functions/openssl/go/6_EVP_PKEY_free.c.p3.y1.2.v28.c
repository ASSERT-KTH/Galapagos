It is not directly possible to convert this C code to Go as is, given Go's garbage collector system that manages memory allocation itself. In Go, you don't manually allocate and deallocate memory like in C. Go also doesn’t have a direct equivalent of using pointers to handle data. 

As a result the `EVP_PKEY_free` function from C would not be required in Go where memory is automatically managed.

In theory, you could use cgo, Go's foreign function interface (FFI), to call into C libraries if you need to execute this or similar functions directly., however, it also eliminates the main advantage of Go that includes easier concurrency and garbage collection.

Below is a simplistic concept of how we might express such function:

go
import (
    "C"
)

func EVP_PKEY_free(x *C.EVP_PKEY) {
    if x==nil {
        return
    }
    
    var i int
    
    // Those functions might not exist in GO as they are probably linked to C OpenSSL library and wasn't translated to Go
    C.CRYPTO_DOWN_REF((*C.int)(&x.references), (*C.int)(&i), x.lock)    
    C.REF_PRINT_COUNT("EVP_PKEY", x.ctypes.c_void_p)
    
    if i > 0 {
        return
    }  
    
    C.REF_ASSERT_ISNT(i < 0)    
    C.evp_pkey_free_it(x)   
    // Deallocating unassigned variables or data structures is automatically done by Go's garbage collector 
    
    // Not ok because might cause problems with Go's garbage collector
    //C.openSSL_free(x.ctypes.c_void_p)    
}

The `// those functions might not exist...` bit is a sign of two other problems. 

Please remember, it is strongly discouraged to use C imported functions as in Go programming it would be better to find a library that has similar functionality in pure Go version. If you use OpenSSL library a lot it would be productive and safer to step out of the Go safe language capabilities to use OpenSSL, due to compatibilities and potential memory issues.