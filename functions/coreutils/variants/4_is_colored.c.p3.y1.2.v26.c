Go does not have enums like C but you can use a simple int type or define a new type and constants. Also, there is no pre-defined length() function or macro in Go. So, the strings package is used to get the length of the string. 

Given all this, here is the semantically equivalent implementation in Go:

go
type IndicatorNo int

var color_indicator = []struct {
    len    int
    string string
}{
    /* ... indicator types would go here ... */
}

func IsColored(type IndicatorNo) bool {
    len := len(color_indicator[type].string)
    s := color_indicator[type].string

    return !(len == 0 ||
        (len == 1 && s == "0") ||
        (len == 2 && s == "00"))
}


Do remember to have the `color_indicator` slice filled before calling the function. As in Go, slice access for non-existing indexes would give a runtime error.

For clarification,
go
var color_indicator = []struct{
    len int
    string string
}{
        {0, ""},
        {1, "0"},
        {2, "00"},
        /* more indicator type definitions... */
        {1, "1"},
    }

You can call the function as:
go
fmt.Println(IsColored(3)) // true
fmt.Println(IsColored(2)) // false
