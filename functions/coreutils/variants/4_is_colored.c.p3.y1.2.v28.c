It isn't possible to match the exact function signature because both C and Go handle enumerations and type definitions very differently. Here is a rewrite that replaces the enumeration with regular integers, and assumes that "colorIndicator" will be a global structure like it often is in C. Go doesn't appreciate global variables like these, so you might consider redesigning the function depending on your specific use case.

Go
type colorIndi struct {
	len    int
	string string
}

var colorIndicator = []colorIndi{
	// Add your elements here
}

func is_colored(type_ int) bool {
	len_ := colorIndicator[type_].len
	s := colorIndicator[type_].string

	return !(len_ == 0 ||
		((len_ == 1) && (strings.Compare(s, "0") == 0)) ||
		((len_ == 2) && (strings.Compare(s, "00") == 0)))
}
