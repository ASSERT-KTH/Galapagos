In the Go language, function implementation might look like this:

Go
const InvaledIndicator = -1

type Indicator struct {
	Len    int
	String string
}

var ColorIndicator = map[int]Indicator{}

func isColored(Type int) bool {
	item, ok := ColorIndicator[Type]

	if !ok {
		return false
	}
	len := item.Len
	s := item.String
	return !((len == 0) || 
		 (len == 1 && s == "0") || 
		 (len == 2 && s == "00"))
}

Explanation:
There is no either Enum or direct equivalent constants in Map in Go. Accordingly, the given type `indicator_no type` enum variable was converted into an int Type value. Also, ColorIndicator array is now a map to achieve dynamic assignment.

Also, in Go, global variables can't be reached using '.' directly, Thus, we manually find demanded Indicator struct from the "ColorIndicator" global map.

Go does not allow to directly use comparison on the full strings as this behavior is delegated to  libraries like strings—for which we replaced STRNCMP_LIT with normal comparision calls (== operator). 

Apart from above, the Go version handles the nonexistent key situation for 'Type'var or cases the Type parameter sent to function is that it is not present in ColorIndicator map.

It is noted that code above doesn't compile standalone unless ColorIndicator is properly initialized and has values inside, since our function directly operates onto it.