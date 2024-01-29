The Go language does not support pointer arithmetic like in C. We also need to change the approach a little bit here - the function below will check if `str` is the same as the first element of `args`. If yes, it will return true and remove `str` from `args`. Otherwise, it only returns false. 

go
package main

import "strings"

func nextArg(args *[]string, str string) bool {
    if len(*args) == 0 {
        return false
    }

    r := strings.Compare((*args)[0], str) == 0
    if r {
        *args = (*args)[1:]
    }

    return r
}


Please pay attention - `nextarg` function is stateless in provided C code (it does not change `args`), but this is impossible in the provided Go analog due to the Go language restrictions. Instead, consider calling this Go function with the same `args` slice every time when you want to check the next argument - this way it will return the same value as the original function would.