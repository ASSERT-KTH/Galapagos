Since Go doesn't support dynamic types and direct memory operations like C, we can't simply free a variable as it's done in C (the Go runtime handles garbage collection). With that in mind, the closest thing we can do is to reset the contents using the default zero-value for data type of this field.

Now, the C code presents a struct that has mixed data types that you are talking about: we call this polymorphism. Here is an example concept, but golang not implement this type. You just can handle it using the concept of interface{} or u can try wrap it to struct to initialise to the certain value:

Go
type Type int

const (
    None Type = iota
    String
    MPZ
)

type StringValue struct {
    val string
}

type MPZValue struct {
    val big.Int
}

type Value struct {
    type  Type
    stringValue *StringValue
    mpzValue *MPZValue
}

func (s *StringValue) Reset() {
    s.val = ""
}

func (m *MPZValue) Reset() {
    m.val = *new(big.Int)
}

func FreeV(v *Value) {
    if v.type == String {
      v.stringValue.Reset()
    } else if v.type == MPZ {
     v.mpzValue.Reset()
    }
    v.type = None
}

But remember, this function just resets the specific members back to their zero values, it doesn't deallocate the memory occupied by them (since we're in Go now). It's a tad safer and lets the garbage collector do it's job.
The memory model in Go is simple -- you create objects, they are garbage collected when no more references to them could be found by the collector. You usually do not think about "releasing" interfaces or structs. It just works.
I hope this will help to provide what you need to know.