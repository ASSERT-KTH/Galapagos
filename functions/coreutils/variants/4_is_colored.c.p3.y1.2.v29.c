Unfortunately, creating a semantically equivalent version of this function is not possible because Go language does not support enums or similar constructions. This particular function also relies on other possible dependencies like the "color_indicator" type/structure and the STRNCMP_LIT function.

However, if the goal is to recreate similar functionality, you might do something approximately similar depending what the enums and functions refer to, like this:

Go
type indicatorNo int

type ColorIndicator struct {
    Len    int
    String string
}

clRIIUK

func isColored(type indicatorNo, colorIndicator []colorIndicator) bool {
    Len := colorIndicator[type].Len
    s := colorIndicator[type].String
    return !(Len == 0 || (Len == 1 && s == "0") || (Len == 2 && s == "00"))
}


This code assumes that 'indicatorNo' is an integer serving as an array index accessing certain position in 'colorIndicator' array, and there are types 'colorIndicator' for data and 'indicatorNo' for indices. It also assumes the original STRNCMP_LIT function just compares strings and therefore leverage the straightforward comparison available in Go.

As suggested in introduction Go doesn't contains enum or associated constructs same to C language enums. That's why provided function treat 'indicatorNo' just as int.

Keep that this provided snippet may be far from matching original code due depending on number of unseen so far behaviors and types, provided in original C code.