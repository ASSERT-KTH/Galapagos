Your request to maintain the "original function's signature" can't be fulfilled directly as C and Go are significantly different, especially in the way they handle enums.

However, the Go snippet equivalent if we abstract the enum to an int and assuming that `color_indicator` is a global slice of a struct containing length and string would be something like this.

go
type colorIndicator struct {
    Len int
    String string
}
var colorIndicators = []colorIndicator{
    // your colorIndicators here
}

func isColored(typeOf int) bool {
    cif := colorIndicators[typeOf]
    s := cif.String
    len := cif.Len
    return !(len == 0 || (len == 1 && s == "0") || (len == 2 && s == "00"))
}


The Go method varies a bit as Go's data structure techniques are different to C's.
Please note, this lacks the robust error checking that would be typically incorporated in idiomatic Go (like attempting to access a non-existent list member, nil checking structure fields, etc.). Ensure to include such checks appropriately if it's the real world distinct situation.