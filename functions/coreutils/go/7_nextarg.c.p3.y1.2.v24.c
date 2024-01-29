go
func nextarg(str string, args *string) bool {
    if *args == "" {
        return false
    } else {
        r := *args == str
        if r {
            *args = (*args)[1:]
        }
        return r
    }
}

This Go function is equivalent of the provided C code. But there are few things to note. C use pointers whereas, Go discourages but also supports pointers when needed. Also In Go, string are values (not pointers) that are readonly slices of bytes with a length, which represent valid UTF-8 sequences. Also nil in Go would represent a nil pointer, and the empty string would be the equivalent of nullptr.

So, nextarg function here compares the provided string with the  current string from the pointer and returns the result if they are same. Then if the strings are same, the next character in args is considered as the next string. 

Since The question did not clearly state the higher context or objective of the nextarg function, hence the necessary adjustments to golang implementation are made according to the interpretation. For different meaning and usage of the original C function, the go implementation might differ in few cases.