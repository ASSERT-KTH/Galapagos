The equivalent Go implementation of this C code taking into account that in Go the structure variable will be accessible directly (as Go does not have a concept of pointers like C), and that string comparison can be done using == operator in Go.

go
import "strings"

func isColored(type indicatorNo) bool {
    length := len(colorIndicator[type].string)
    s := colorIndicator[type].string
    return !(length == 0 ||
        (length == 1 && strings.Compare(s, "0") == 0) ||
        (length == 2 && strings.Compare(s, "00") == 0))

}


Note: 

- The type `IndicatorNo` might need to be defined to match the original C enum. 
- I have assumed `colorIndicator` as an array or slice of structs where each struct contains a `string` field which is what was being accessed in original C function, as details regarding these were not available in the original snippet.
- You might need to change `colorIndicator` and `indicatorNo` to match respective variables, their types, and scopes present in the original C setup while utilizing this Go function version.
- `strings.Compare` in Go returns 0 if both strings are equal, reproducing the functionality of `STRNCMP_LIT`.