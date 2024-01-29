Go doesn't support OpenSSL out of the box like C, the way C uses OpenSSL to deal with Big Num directly by using the Pointers will not work in Go. 

The go standard library `math/big` package provides functionality for big numbers. Go could handle memory management transparently.

If you use `free` function in Go specifically to release memory it goes against Go's philosophy. Go is garbage collected and does not require you to explicitly free memory. Instead, memory is automatically recovered by the runtime after nothing references it anymore. 

So, it is not directly possible to write a semantically equivalent code unless we assume a few hypothetical scenarios with custom types and API. Even those assumptions would go significantly outside the realm of Go. The main difficulty lies in the differences between memory management methodologies in C (manual) vs Go (automated garbage collection).
  
However, If you want free a BIGNUM manually, you can set it to nil, forcing the GC to free the memory. Here is the equivalent in context.

Important: Because using manual freeing goes go with a life cycle management which based on machine perspective, and GC uses life cycles based on perspective of semantics and it Could be safer.

go
import "math/big"

func BN_free(a *big.Int) {
	a = nil
}


This function sets the argument to nil, which means GC can collect the memory. But note that values referenced by other variables are not collected.

Prefer the Go way of using mem (just allow gc to do whole things). Avoid using any kind of `free` function or memory management by your own in Go.
Remember Go is garbage collected and it handles complex execution scenarios to manage memory even more efficiently than manual cleanup (which is error-prone).

So it's not recommended method of doing it but there it is.