The original function is in C language which references some kind of array or container `color_indicator` and an enumeration `indicator_no`. 

Go doesn't have strict equivalent for C's enums as you would use them in C. You can use constants in Go or you can use 'iota', which is a keyword represent successive untyped integer constants. No direct access to strings like C `char` are available in Go. You would need to manually obtain characters with direct array-like access.

Considering the Go environment where this function would be running, here we use equivalent Go elements for desired mentioned aspects.

go
type IndicatorNo int

const (
	// define enum values
)

type ColorIndicator struct {
	Len    int
	String string
}

var colorIndicator map[IndicatorNo]ColorIndicator

func IsColored(t IndicatorNo) bool {
	len := colorIndicator[t].Len
	s := colorIndicator[t].String
	return !(len == 0 || (len == 1 && s == "0") || (len == 2 && s == "00"))
}


Considering color_indicator as a global `map`, setup outside this function. 
The implementation and elements of data model IndicatorNo and colorIndicator should be according to the scope of overall software.