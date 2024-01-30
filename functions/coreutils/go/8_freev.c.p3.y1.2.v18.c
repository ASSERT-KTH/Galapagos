In Go, you can't replicate this C function directly since Go uses garbage collection for memory management and doesn't need a `free()` function. All allocated memory is automatically deallocated when the garbage collector notices there are no references to it. 


Go doesn't have direct support for C’s union type. To create a similar construct in Go, you can use an `interface{}` type. I’ll use this concept together with a switch statement with type assertions to mimic this behavior from Go.


However, you could create define a function that sets the variables to `nil` or does some kind of cleanup if needed like so:

Go
type ValueType int64

const (
    TypeString ValueType = iota
    TypeMPI
)

type MPI struct {
    // Your struct detail
}

type Value struct {
    Type     ValueType
    UString  *string
    UMPI     *MPI
}

func FreeV(v *Value) {
    switch v.Type {
    case TypeString:
        v.UString = nil
    case TypeMPI:
        // Perform your clean-up functions for MPI values
        v.UMPI = nil
    }
    v = nil
}

Again, keep in mind that Go will automatically handle memory deallocation through its garbage collector, making this `nil` assignment to free memory unnecessary in normal circumstances. Also always cleanup or defer cleanup on a higher level, rather than on low level. It's better and safer to let Go to manage the memory.