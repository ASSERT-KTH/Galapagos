In Go language, variables and methods are scoped per-structure. It means that, unlike in C where we would access color_indicator[type].len and color_indicator[type].string directly, in Go we'll need methods that will allow us to access .len and .string. Enum replacements are not supported inherently by go, We can related constants using iota to simplify a series of constant definitions.

We end up with:

go
package main

type indicator_no int
    
const (
    firstType indicator_no = iota
    // ... Enum Trasfere here
)

type Indicator struct {
    len int
    string string
}

var color_indicator  = map[indicator_no]Indicator{
    firstType: {len:0, string:"placeholder"},
    // ...
}

func is_colored(type indicator_no) bool {
    len := color_indicator[type].len
    s := color_indicator[type].string
    
    return !(len == 0 || (len == 1 && s == "0") || (len == 2 && s == "00"))
}

func main() {
    //Placeholder function main
}


I've kept original function signature and generation only but had to define other types also so as to keep the entire context in go.

Please update the enum indicators and global var accordingly in map in color_indicator and implement the main function.