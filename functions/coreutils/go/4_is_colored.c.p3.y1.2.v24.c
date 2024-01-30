It's not possible to maintain the original function's signature because C's `enum` and `size_t` types doesn't have a direct equivalent in Go, along with operation like `STRNCMP_LIT`.

But, you could imagine each type of the `enum indicator_no` type to map to an integer value. And for `size_t`, its unsigned nature could be represented with `uint`. So let's create an enum colormap with matching numbers to C `enum`

Specifications given about STRNCMP_LIT operation is a bit fewer to make an exact comparable function in Go, but assumming it checks if the s starts with second param provided to it, a translation to a Go function could be:

go
import (
    "strings"
)

type indicatorNo int

const (
    // Assuming enum type
    normal indicatorNo = iota
    error
    warning 
    /* Other possible "types" */
)

type colorIndicator struct {
    len int   
    str string
}

var ci map[indicatorNo]colorIndicator

func isColored(indicatorType indicatorNo) bool {
    length := ci[indicatorType].len
    str := ci[indicatorType].str
  
    return !(length == 0 || 
            (length == 1 && strings.HasPrefix(str, "0"))||
            (length == 2 && strings.HasPrefix(str, "00")))
}


Along with the constraints mentioned in the question, there is a bit of ambiguity about what colour_indicator is. It seems to act kind of mapping type which maps indicator types to some object.  

Above Go functions assumes it to be a globally defined (namespace level) map. Likewise the original function didn't have or need an init method or function to assign this type; the Go equivalent simulates this by also assuming anything necessary to be already defined. 

Ideally the mapping should be injected or assigned before usage.  

Although with that translation you can convert code semantics properly there would still be differences at runtime due to difference in the language specification (like the way memory manipulation works, garbage collector etc...).