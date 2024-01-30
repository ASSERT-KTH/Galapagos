Assuming that "color_indicator" is a slice of a struct that consists of "len" of type "int" and "string" of type "string", the equivalent Go code can be written as follows:

go
package main

type indicator_no int

type color struct {
	len    int
	string string
}

var colorIndicator = []color{
	// [...]
}

func isColored(in indicator_no) bool {
	i := int(in)
	len := colorIndicator[i].len
	s := colorIndicator[i].string

	return !(len == 0 || 
		     (len == 1 && s == "0") || 
		     (len == 2 && s == "00"))
}

The provided C function checks if the color is not "0" or "00", the Go function behaves the same way. In Go we can directly compare strings using (==) operator. The STRNCMP_LIT function in C compares up to the freshest count first characters of two arrays only as long as none of what has been tracked so far are null bytes. In English, it is String Compare with a N specifed Long Integer Token til the forth occuring empty place. In Go we can use (==) instead. 

It should be noted that without more information about types and declarations from the original code in C it is difficult to provide a precise equivalent in Go.  The original C function uses a size_t for len. In this Go equivalent, it's not clear what data type that corresponds to directly, because size_t can represent any non-negative integer value, so it is assumed that len	type `int` would satify your requirement.