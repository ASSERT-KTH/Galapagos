There is no direct equivalent in Golang because Golang handles memory and mutex differently from C, and some functions such as `EVP_PKEY`, `CRYPTO_DOWN_REF`, `REF_ASSERT_ISNT`, `CRYPTO_free_ex_data`, etc., are OpenSSL specific and don't have a direct counterpart in Golang standard libraries. OpenSSL is written in C and is unfortunately not very portable to Go due to critical differences in how the two languages operate, including automatic garbage collection in Go and vastly different concurrency models.

However, I can give you some general tips on how to go about porting this code. This code appears to be concerned with decrementing a reference counter on an OpenSSL encryption key, and freeing memory and resources if the reference count has dropped to zero. 

To do equivalent things in Go, you could use the `sync` package's `Waitgroup` or `Mutex` in place of the CRYPTO_DOWN_REF function, though the exact implementation will depend on the rest of your system. 

Memory and resource management will largely be handled automatically with garbage collection, save ensuring you `Close()` anything implementing `io.Closer` when it is safe to do so. Custom types equivalent to your `EVP_KEY` can have their cleanup routines implemented in a `Close()` or `Release()` method on the struct on your code. 

For most use cases, you can possibly consider using some Go cryptography libraries, like "crypto/rsa", "crypto/ecdsa", etc. Here you won't likely need to manage memory as you would do in C.

Remember, by doing so, it would require re-engineering your whole application/feature. So the ultimate decision lies upon your app's specific requirements. If you have only bit parts of your application written in C/C++, you can use cgo to manage the communication between Go code and C code.