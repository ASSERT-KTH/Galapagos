In the context of this problem, it's important to note that `STRNCMP_LIT(s, "0") == 0` and `STRNCMP_LIT(s, "00") == 0` are C idioms for `s == "0"` and `s == "00"` respectively.
So, using this understanding, here is the equivalent function in the Go programming language:

go
func is_colored(color_indicator []ColorIndicator, typ IndicatorNo) bool {
    len := color_indicator[typ].len
    s := color_indicator[typ].string

    return !((len== 0) ||
             (len== 1 && s == "0") ||
             (len == 2 && s == "00"))
}


Please note that this assumes that `ColorIndicator` and `IndicatorNo` are types defined in your Go code that are similar to equivalent types in the initial C code expressed. For instance:

go
type ColorIndicator struct {
    len int
    string string
}

type IndicatorNo int
