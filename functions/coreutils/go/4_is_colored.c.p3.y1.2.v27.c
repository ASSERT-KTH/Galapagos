Code implementing the above C function in Go is as strong as stated earlier, that due to languages type differences it might not be exactly the same but also when working on translation certain assumptions have been made providing rational, since original query is provided without any context.

However, given signatures and guidance on procedural flow, here is a very raw idea to accomplish the same objective in Go for the following C code:

For completing the assumptions as mentioned below:

    color_indicator[type] is a slice of type, where type is a struct with len as int and string is a "string".
    
    STRNCMP_LIT(str1, str2) is equivalent to strings.EqualFold(str1, str2) in Go, which compares two strings in a case-insensitive manner.


So Go code can be as follows:

Go
// Assume IndicatorType is defined as specified,
// IndicatorNo is enumeration for the index, something like using iota in Go
type IndicatorType struct {
    Len    int
    String string
}
var ColorIndicator []IndicatorType

// Iota for IndicatorNo
type IndicatorNo int
const (
    Indicator1 IndicatorNo = iota // represents enum index 0
    Indicator2 // index 1
    Indicator3 // index 2
    ...
)

func IsColored(tp IndicatorNo) bool {
    len := ColorIndicator[tp].Len
    s := ColorIndicator[tp].String
      
    switch {
    case len == 0:
        return false
    case len == 1 && strings.EqualFold(s, "0"):
        return false
    case len == 2 && strings.EqualFold(s, "00"):
        return false 
    default:
        return true
    }
}


[Can refer further about Iota in Go to come up as equivalent to Enums in C](https://yourbasic.org/golang/iota/)