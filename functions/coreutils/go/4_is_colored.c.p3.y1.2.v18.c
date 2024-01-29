The original C function's structure can be recreated in Go, however, mapping it directly is not possible since Go doesn't have enums and their structs like define `color_indicator`. However, an equivalent function with assumed color_indicator definitions could look similar to this, it uses type hinting to guide the function:

Go
import (
    "strings"
)

type Indicators struct {
    Len    int
    String string
}

var colorIndicator = []Indicators{
    {Len: 0, String: ""},
}

func isColored(type int) bool {
    len := colorIndicator[type].Len
    s := colorIndicator[type].String

    return !(len == 0 ||
            (len == 1 && strings.HasPrefix(s, "0")) ||
            (len == 2 && strings.HasPrefix(s, "00")))
}


Please note that when writing analogous function for different programming languages, language specifics need to be carefully considered. Always follow the best practices of the target language.