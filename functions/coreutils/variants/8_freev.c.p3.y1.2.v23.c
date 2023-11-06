In Go, we don't explicitly free memory like in C. Instead, native garbage collector will do the job for us automatically when some memory is not used anymore. Also Go isn't meant to provide fully compatibility with C, so some of operations can be done only explicitly.

However, a semantically equivalent version of the code would look something like this:

go
func freev(v *VALUE) {
    if v.typeValue == stringType {
        v.u.s = ""
    } else {
        v.u.i = new(big.Int) // mpz_clear resets value to 0
    }
    v = nil
}


Note here, I assumed `typeValue` to be the field name replacing C `type` which can't be used in Go as it's a reserved word. `stringType` is assumed to be a constant deciding the type of `u`. Also, `big.Int` from `math/big` package seems most suitable library to replace C `GMP` library's `mpz_t`. 

The `v.u.s = ""` resets the string value, letting garbage collection help. `v.u.i = new(big.Int)` creates a new Int which essentially makes the Int's value 0 much like mpz_clear does in C. Finally, `v = nil` is the closest thing to `free` in Go, with garbage collection taking care of the rest. Inputs or situations where those assumptions do not meet have to be handled differently.