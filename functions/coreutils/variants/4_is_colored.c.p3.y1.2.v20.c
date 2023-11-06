**Note:** I will create the Go function taking into thought that we have access to a global `colorIndicator` map with a structure similar to this:

Go
type Indicator struct {
	Len    int
	String string
}
var colorIndicator map[string]Indicator


This would be reflecting aC-style enum which doesn't exist in Go. Similarly, Go has no direct in-built alternative to C's `STRNCMP_LIT` String comparison. A rough assumption is made by logically calculating equivalence via Go's initial substring comparison. This is the final conversion:
Go
func isColored(typeIndicator string) bool {
	len := colorIndicator[typeIndicator].Len
	s := colorIndicator[typeIndicator].String
	return !(len == 0 || 
		(len == 1 && strings.HasPrefix(s, "0")) || 
		(len == 2 && strings.HasPrefix(s, "00")))
}
