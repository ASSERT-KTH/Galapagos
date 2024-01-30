Given the pseudocode-like nature of the provided C code, the corresponding Go implementation might differ based on your actual definitions and environment. Assuming that 'VALUE' is a struct with fields 'Type' to define the `datatype` and 'U' to define the `data` stored in union type (as it could be a string or an arbitrary precision integer). It's important to make sure the fields have appropriate Go data types in your program. However, the equivalent implementation would be like this:

go
import (
    "math/big"
)

type Data struct {
    s string
    i *big.Int
}

type VALUE struct {
    Type DataType
    U    Data
}

type DataType int

const (
    String DataType = iota
    Int
)

func freev(v *VALUE) {
    switch v.Type {
    case String:
        // Go automatically frees memory on string's scope exit (uses garbage collector)
        v.U.s = ""
    case Int:
        // can nil out pointer or use Reset if you want to use in future
        v.U.i = nil
    }
    // Go automatically frees variables after scope exit (uses garbage collector)
    v = nil
}


Assumptions/best practice have been made:
* Go does cannot "explicitly" free memory like we do in C using `free()`, instead the management of the heap is done by Go's garbage collector.
* Here, we're by resetting the `string` or `*big.Int` values to zero(`"" and nil`), we're sort of implying that content in this location at this time is no longer needed.
* Assuming, switching on "type detected for the union approach". and based on the `type`, handling the different 'values', either of `string` type or of `*big.Int`.
* The complexity and semantics might vary based upon the requirements that haven't been explicitly stated in the question and need to de-decided on.
Note:
Map `free(...)` directly to `nil` is incorrect in general, though it does free up the reference similarly in common cases. Go's garbage collector looks for references to the data, and so as long as there are remaining references in other data structures, replacing a single reference with `nil` will not result in that memory being freed. The garbage collector iteratively marks reachable memory (starting with the local and global memory) and then reclaims non-marked memory.