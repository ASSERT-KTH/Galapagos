There might be some misunderstandings in the context of C code given because some variables like 'args' and 'STREQ' are not defined. If on the assumption that 'args' refers to passed string as a pointer and STREQ is the same as the string comparison function 'strcmp' in C, we would translate the code in Go as:

go
import "strings"

func nextArg(args *string, str string) bool {
    if args == nil {
        return false
    } else {
        r := strings.Compare(*args, str) == 0
        if r {
            *args = strings.TrimPrefix(*args, str)
        }
        return r
    }
}

But in reality this function wouldn't see a lot of use in Go-land because strings in Go aren't nullable and modifying them in place is rarely needed (unlike C where both are common operations). Therefore, the equivalent idiomatically go version may look more like this:

go
import "strings"

func nextArg(args, str string) (bool, string) {
    if strings.HasPrefix(args, str) {
        return true, strings.TrimPrefix(args, str)
    }

    return false, args
}


Because of the nature of the language, it isn't really possible to create a perfect 1:1 conversion of this function. This version does as similar an operation as possible considering the language particulars.