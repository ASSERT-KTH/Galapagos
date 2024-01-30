Assuming "args" is a string, since the reference function is written in C++ which doesn't provide clarity about what type "args" really is, and implementing a C++ null pointer in Go isn't straightforward due to Go's strict type system, a semantically equivalent Go function might look like this:

golang
func nextarg(str *string, args *string) bool {
    if *args == "" {
        return false
    } else {
        r := (*args == *str)
        if r {
           *args = (*args)[1:]
        }
        return r
    }
}

Noteworthy implementation details to interpret this translation:

1. str and args are pointer to a string. Just following the C function which receives string (*char ) as an argument.

2. We are replacing `args+=r` translation without any context quite challenging. But in C++, when a pointer plus an integer, it simply increases the pointer value by the integer. Thus, optimistically assuming that for true, we must increase args pointing by 1 or move one step.

3. We are replacing `nullptr` using an empty string `""`. In Go there is `nil` but as it's a strongly typed language, we can't use nil for string instead we use "".

This translation is done without knowing the context or usage of original function. Thus, semantics as shown in given `C++` code is respected as thoroughly as possible. Please adapt based on actual usage context for maximum accuracy.