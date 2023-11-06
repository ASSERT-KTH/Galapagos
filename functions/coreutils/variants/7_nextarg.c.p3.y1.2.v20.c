The C code provided is not valid since it references `args` which is neither a parameter nor a global variable. There is also a direct comparison of string (`STREQ(*args, str)`) through function call but Go doesn't need that. We just need string comparison. Here is the Go version function based on the available information:

go
func nextArg(args *string, str string) bool {
    if args == nil {
        return false
    } else {
        r := (*args == str)
        if r {
            *args += str
        }
        return r
    }
}


Here `args` is a pointer (reference) to a string which can be detected if `nil` analogous to `nullptr`. If the pointer is not `nil` then the Go string which it points to can be compared directly to the parameter `str`, and incrementation of `r` is achieved by string concatenation if needed (although we cannot actually increase string as in c but string concatenation will have same human readble effect in Go). 

Please adjust if this does not completely meet your needs.