Assuming that the C code is part of a custom database library (where ldb seems to stand for LeveldB, a popular key/value store), this is a C implementation directly, but Go doesn't have direct memory management in the form of free or alloc.

In Golang, memory management is automatically handled for us with Garbage Collector. Therefore, the equivalent Go function would not require directly freeing the memory. Instead, we just need to nil-out or redefine the attributes.

Your struct might look like this:

type LdbBuffer struct {
    Data []byte
    Size int
    Alloc int
}

The equivalent function to clear the buffer data might look like this:

func (ldb *LdbBuffer) Clear() {
    ldb.Data = nil
    ldb.Size = 0
    ldb.Alloc = 0
}


Above function Clear sets Data to nil and Size and Alloc to 0, which is functionally equivalent of the original C code in garbage collected environment. It effectively empties ldb.Data, and allows for all memory previously associated with it to be released by GC.