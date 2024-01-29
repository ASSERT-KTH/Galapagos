There seems to be a confusion the provided C code. It uses both 'arg' and 'args'. Without clarification, I will assume a function declared as `bool nextarg(char const **args, char const *str)` was intended and translate that correctly to Go:
go
import "strings"

func nextArg(args *[]string, str string) bool {
    if len(*args) == 0 {
        return false
    } else {
        eq := (*args)[0] == str
        if eq {
            *args = (*args)[1:]
        }
        return eq
    }
}

This Go function behaves close to your C function if assuming my interpretation of your C version. In Go, `args` need to be a slice of string (`[]string`) and does not have direct equivalent of C's `char const **args`. The Go version checks if the first value (*args[0]) is equivalent to the input string (str). If equivalent, shifts the slice to the immediate next value. 

WARNING: This still operates on the address of slice input not on its copy, therefore it indeed changes the initial slice. If that's not okay, more complex approach is necessary involving creating own type that will hold both slice of strings and current index.
Please clarify the intent in your C version for more precision.