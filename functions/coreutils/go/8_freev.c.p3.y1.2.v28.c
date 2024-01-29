In Go, manual memory management is not typically necessary due to garbage collection, therefore there's no direct associated function like free in C. Further, the Go equivalent type to `VALUE` could have methods (since Go supports methods on custom types) to clear each type if needed. It could be conceptualized as below:

Go
type VALUE struct {
    StringType *string
    IntType    *big.Int
}

func freeValue(val *VALUE) {
    if val.StringType != nil {
        *val.StringType = ""
        val.StringType = nil
    } else if val.IntType != nil {
        val.IntType = new(big.Int)
    }
}

Without more context, a more accurate version can't be provided as union types don't exist natively in Go and would be typically modeled using interfaces or pointers.