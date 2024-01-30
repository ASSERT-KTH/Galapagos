In Go, there's automatic garbage collection so dynamic memory released when no longer used, but in order to match the exact requirement, we can make use of Go's finalizer which can effectively release or reset some resource as required (though avoid using them as a cleanup mechanism). 

Since data types are a bit more concrete in Go than in C, let's assume we have a TYPE_ENUM defined which helps us identify what kind of Value we have, so we need to create a Type for that and then access it accordingly. Here's how it could be done:

go
// enum type to represent the value type
type TYPE_ENUM int

const (
        TYPE_STRING TYPE_ENUM = iota
        TYPE_INT
)

// assuming u is a struct which contains either int or string.
type U struct {
        s string
        i *big.Int
}

type VALUE struct {
        type_ TYPE_ENUM
        u     U
}

func freev(v *VALUE) {
        if v.type_ == TYPE_STRING {
                runtime.SetFinalizer(&v.u.s, func(s *string) {
                        *s = "" // just reset the string, by empty string literal
                })
        } else {
                runtime.SetFinalizer(&v.u.i, func(i **big.Int) {
                        *i = new(big.Int) // just zeroing out the arbitrary precision integer
                })
        }

        runtime.SetFinalizer(v, func(v *VALUE) {
                *v = VALUE{} // zero out the entire struct
        })
}


This guarantees that content would be cleaned as it is asked, though Go's GC would automatically clean unused memory, it tends to clean up memory no longer in use but no effect on other resources - for instance it won't clear a field inside the struct or nil a pointer. 

Please Note: not a recommended way for general Go programming, improper use of `runtime.SetFinalizer` could lead to memory leaks.