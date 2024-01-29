As the C version uses pointers and direct memory manipulation to free certain values, which Go doesn't support, you should model VALUE such that it can handle an underling clean-up task when it gets destroyed. From your example, the cleanup needed is either free a string or clear an integer value. Therefore, it could be translated to the Go equivalent is something like this:

go
type ValueType int

const (
    STRING ValueType = iota
    INTEGER
)

type VALUE struct {
    Type ValueType
    StrVal *string
    IntVal *big.Int
}

func freev(v *VALUE) {
    if v.Type == STRING {
        v.StrVal = nil 
    } else if v.Type == INTEGER {
        v.IntVal = nil 
    }
    v = nil
}


This version sets the elements of the struct to `nil`, which is the recommended way to "free" or "delete" something in Go, leaving the garbage collector to remove it completely. Notice that Go does not support manual memory management model (e.g., direct freeing memory as you have done your [C] pieces of code via `free()` or `mpz_clear()` been removed). It uses garbage collector for automatic memory management.
Only clearing the structure VALUE by assigning `nil` to it do not clear the underlying types in it.

Avoid trying to manually release and refactor it instead to return new objects without referencing old discarded ones and rely on standard Go garbage collection.

Keep in mind though, sometimes proper cleanup in Go might involve more than just dereferencing a variable, like properly closing file handles or database connections etc. which isn't required in this solution but might come handy anytime you are considering translating such functions.