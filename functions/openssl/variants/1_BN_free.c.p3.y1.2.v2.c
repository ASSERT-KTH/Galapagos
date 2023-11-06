As we talking about coding cryptography related function BN_free equivalent, there is no exact equivalent translation since Go provides bigInt in math/big package in the Standard Library.

Moreover, Go language uses garbage collection to automatically manage memory management, so there is usually no need to write the equivalent of a free function.

However, a rough conceptual go equivalent of this code that manually releases the runtime system's resources could be written with finalizers in the runtime package:

go
	import "runtime"
	
	type BIGNUM struct {
		malloced bool
		staticData bool
	}
	
	func BN_free(a *BIGNUM){
		if a == nil {
			return
		}
		if !a.staticData {
			runtime.SetFinalizer(a, nil)
		}
		if a.malloced {
			runtime.SetFinalizer(a, nil)
		}
	}


Here, runtime.Setfinalizer with nil finalizer could be thought as a general access release of resources.
Nevertheless, cleaning of these kind data objects often done automatically which is the beauty of GO. But here represented done manually to present a concept on function proivded.