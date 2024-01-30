In Go, garbage collection is automatic, so there's no need for a manual free function. The second operation seems to be related to a large integer arithmetic library (GMP). We don't have an replica of mpz_clear but for the equivalent behaviour in Go we can set the value to 0 to allow the garbage collector to free up the memory.

go
func freev(v *VALUE) {
	if v.type == "string" {
		v.u.s = ""
	} else {
		v.u.i = big.NewInt(0)
	}
	v = nil
}


Keep in mind, however, that this function changes VALUE, but it would not have any effect outside of the function, because Go passes pointer's copy when a pointer is passed to a function; so the actual VALUE object elsewhere in your program would still influence same memory as previously.
To have actual influence, you should omit line v = nil, and do that in your main function, where the value was declared/defined.