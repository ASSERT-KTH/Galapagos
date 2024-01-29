Assuming that colorIndicator is a struct with `string` and `len` as properties in Go context equivalent to what provided in the C variant.

go
type Indicator struct {
	len   int
	string string
}

var colorIndicator = []indicator{}

func isColored(type Indicator) bool {
	len := colorIndicator[type].len
	s := colorIndicator[type].string
	return !(len == 0 ||
		(len == 1 && s == "0") ||
		(len == 2 && s == "00"))
}
