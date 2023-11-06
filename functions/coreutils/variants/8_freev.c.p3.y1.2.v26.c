In Go, memory management is automatically handled by the garbage collector. Also, Go uses Interfaces for Polymorphism. Here's a simple translation of your C code to Go. In the example, the `Value` is an Interface that could have a `String` or an `mpz.Integer` type.

Note: The Go's standard library doesn't have an equivalence for `mpz_clear`, and Go doesn't typically deal with memory management. If you use an external library for dealing with large integer which requires manual cleaning, then you need to obey the library's instructions.

Go
func FreeValue(v Value) {
    switch value := v.(type) {
    case StringValue:
        value.Content = ""   // not really necessary as memory management is automatic in Go
    case IntegerValue:
        value.BigInt = nil  // or call any clean up function according to the library used
    }
}


And create the required types
Go
type Value interface {}

type StringValue struct {
    Content string
}

type IntegerValue struct {
    BigInt *big.Int  // Using Go's standard math/big library to handle large integers
}
