In Go, an equivalent code snippet might look like so:

go
import (
    "strings"
)

type Indicator struct {
    Len    int
    String string
}

func IsColored(type_indicator Indicator) bool {
   len := type_indicator.Len
   s := type_indicator.String
   return !((len == 0) || 
            (len == 1 && strings.Compare(s, "0") == 0) || 
            (len == 2 && strings.Compare(s, "00") == 0))
}


Notes:

1. In Go, function names start with a Capital letter if they need to be accessed outside the package.

2. `strings.Compare` function in Go is used to compare strings, returns 0 when both strings are the same.

3. It appears the input to your original C function is an enum of a struct type `indicator_no` whose instances access properties like `len` and `string`. Depending on the exact relationship between `indicator_no` and its properties, you might need to make minor adjustments to align with struct use in Go. The above provided Golang setup indicates a struct named Indicator with field `Len` and `String`, and the function `IsColored` takes an instance of `Indicator` as argument to work with those fields.  Remember to instantiate instances of the struct and use method calling `.Len` or `.String` on the instance to get necessary values for necessary further actions within the function.

4. In C, identifiers are usually snake_case whereas in Go, they're usually CamelCase.

EDIT: Adjusted based on changes suggested!