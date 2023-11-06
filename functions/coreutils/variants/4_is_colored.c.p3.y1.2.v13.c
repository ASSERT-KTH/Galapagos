It is critical to note we need some form of access to the color indicator array and the equivalent of the `STRNCMP_LIT` macro in Go. Though the specific strategy of retrieving the needed information and make the comparison could change based on your Go development environment, I will provide an example of a potential Go equivalent below:

Enumerators in C can essentially be replaced by types and constants in Go. Therefore, the classifier indicating the type can be declared like this:

Go
type IndicatorNo int


As for colorIndicator, you could have something like this, assuming that the `colorIndicator` array was initially defined in the C code which have key as enumeration type and value as a struct holding a string and its associated length:

Go
type colorType struct {
	length int
	str    string
}

var colorIndicator = map[IndicatorNo]colorType{
  // all your color indicators goes here Eg:
	INDICATOR_ONE: {length: 2, str: "1"},
	//...
}


Here's a possible conversion of the C function to Go.

Go
func isColored(i IndicatorNo) bool {
	colorIndicatorValue, exists := colorIndicator[i]
	if !exists { // Check if the key exists in the map, it is Go equivalent check of Array.
		return false
	}

	len := colorIndicatorValue.length
	s := colorIndicatorValue.str

	return !(len == 0 || (len == 1 && s == "0") || (len == 2 && s == "00"))
}

The Go function will check if the key `i` exists in the map colorIndicator, if not it returns false. After that it fetches the `length` and `str` from the map and and evaluates the same conditions as in the C code. Note: since Go does not directly support operator for string cross checking hence direct comparison of strings is used here. The operation `STRNCMP_LIT (s, "0") == 0` checks if the string `s` is equal to "0" (evaluates to zero or false).