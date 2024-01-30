Unfortunately, Go does not support enums like C does. Also, the implementation here relies on the behavior of a function `STRNCMP_LIT` which does not exist in Go either.

However, Go does have map, and we can create a map to simulate the behavior of the `color_indicator` array in C. We can assume that `type` here now becomes a `string` in Go, as map keys in Go cannot be of type `enum`.

The essence of the function is that it checks if the string of a certain type is not "0" or "00". In Go we would use the `strings.Compare` method to accomplish this. It returns an integer. 0 if both strings are the same, -1 if the first string is "less" than the second, and 1 if the first string is "greater".

So here is the Go equivalent:

go
import "strings"

type color_indicator struct {
    len    int
    string string
}

func is_colored(cType string, color_map map[string]color_indicator) bool {
    sLen := color_map[cType].len
	var s = color_map[cType].string
	return !(
		sLen == 0 ||
		(sLen == 1 && strings.Compare(s, "0") == 0) ||
		(sLen == 2 && strings.Compare(s, "00") == 0))
}


Notice that, for simplicity, I have removed the `enum` and behave `color_indicator` as a `map` with `string` keys(as we can use `string` to identify a key in Go). So they look a little bit more verbose. This version unfortunately differs to some extent from the original because of each language's strengths, weaknesses, and design choices.