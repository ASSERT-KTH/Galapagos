In the Go programming language, it is generally not necessary to manually deallocate memory. The garbage collector automatically recovers the allocated memory that is not in use.

But, considering some semantics in C related above, the equivalent patterns in Go are `defer` with `Close` for `io.Closer`.

In this hypothetical platform where your VALUE struct contains io.Closer objects, the function could look like the one below (`io.Closer` should be replaced with your actual objects):

go
type ValueType int

const (
	String ValueType = iota
	Integer
)

type VALUE struct {
	Type ValueType
	Sc   io.Closer  // equivalent to u.s - hypothetical string equivalent
	Ic   *big.Int // equivalent to u.i - hypothetical mpz equivalent
}

func freev(v *VALUE) {
	if v.Type == String {
		defer v.Sc.Close()
	} else {
		defer v.Ic.Clear() // big.Int has not Clear func, you should replace all with your correct values
	}
	v = nil // set v to nil if that's considered freeing it up?
}


Just be aware, `big.Int` has not Clear func as mpz in C. Be sure replace with your correct values/functions/struct! Defer is used here, comparable to Deconstructors (Form of freeing) in C++. Close is commonly setting contents to nil and returning the object back to heap in a "nice way". 

Disclaimer: You should take care on concurrency "object should be used in only one goroutine if" applicable in your real object! 

Please, consider consulting Go practices manuals official or other benchmarks/libs which use similar practices/structures.
