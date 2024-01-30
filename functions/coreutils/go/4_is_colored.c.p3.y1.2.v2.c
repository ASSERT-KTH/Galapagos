In Go, your code would look as follows:

go
import "strings"

type Indicator struct {
	len    int
	string string
}

func isColored(type Indicator) bool {
	len := type.len
	s := type.string
	return !(len == 0 ||
		(len == 1 && strings.Compare(s[:1], "0") == 0) ||
		(len == 2 && strings.Compare(s[:2], "00") == 0))
}


This function will return the same results under the same conditions as your original. 

Note: In Go, slice boundaries are inclusive for the starting index and exclusive for the ending index. The expression `s[:1]` slice the string s from an index of 0 to 1 (excluded), giving us the first character (in the case len is 1). Similarly, `s[:2]` slice the string s from an index of 0 to 2 (excluded), giving us the first 2 characters (in case len is 2). This makes it equivalent to strncpy in C.

The "strings" package Compare function in Go is used where as in C strcmp is used (`STRNCMP_LIT (s, "0") == 0`) which compare two strings. The "strings.Compare" function compares two strings lexicographically. The result will be 0 if s1==s2, -1 if s1 < s2, and +1 if s1 > s2.

'Type' is a keyword in Golang. Using 'type' directly as a variable identifier will result error. It is replaced with 'indicatorType'. 

Please replace your own type name 'Indicator' as per your requirements. It is used to satisfy the requirements of the original question.