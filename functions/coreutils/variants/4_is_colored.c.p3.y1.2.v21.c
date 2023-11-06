It is a bit challenging to directly translate this C code into Go because enumerated types work differently in Go and Go doesn't have a string function exactly like STRNCMP_LIT that exists in the given C code.

I made the assumption that we're dealing with a predefined global slice of structs, each of them having len and string properties. This would be roughly similar to the global color_indicator array in C.

First it is necessary to create `colorIndicator` and `IndicatorNo` equal to in C
Go
type IndicatorNo uint

type color struct {
    length int
    string string
}

var colorIndicator []color

The equivalent function in Go may be:
Go
package main

func isColored(typ IndicatorNo) bool {
	len := colorIndicator[typ].length
	s := colorIndicator[typ].string
	
	// return the inverse of these conditions
	return ! (len == 0 || (len == 1 && s == "0") || (len == 2 && s == "00"))
}

In Go, type inference is leveraged (`len` and `s` automatically take the appropriate types), `len` replaced `length` because `len` thought to be more Go idiomat code then `len`, slices are used instead of arrays for greater flexibility, and a string comparison is simply performed with `==` instead of using a string comparison function like `STRNCMP_LIT`.