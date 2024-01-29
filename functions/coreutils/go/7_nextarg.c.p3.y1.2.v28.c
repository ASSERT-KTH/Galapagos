If we look at C function, it compares string pointed by `arg` with string `str` and returns whether these strings are equal or not. If they equal, `arg` points to the next character in `args`.

The mentioned function uses features that are really not common for Golang, like pointers and string processing, because those aren't heavily used in this setting in Golang.

Instead, I will create a semantically equivalent function that follows common practices in Golang:

go
func nextArg(args *string, str string) (b bool) {

    if args == nil {
        return false
    }

    b = (*args) == str

    if b {
        if len(*args) > 0 {
            *args = (*args)[1:]
        }
    }

    return b
}


In this implementation, the method checks whether provided string `args` equals to string `str` and assign the result to boolean variable `b`. Based on result of that comparison we either remove several symbols from `args` using slicing, or not. Returning boolean flag similar to the C code you posted.