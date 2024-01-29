In Go, we don't have pointers to functions as we have in C. But we can use function values. The concept of critical section exists in concurrency managing in Go, but we also do not have direct conversion of sodium_crit_enter and sodium_crit_leave from C to Go.

go
var misuseHandler func()

func SodiumMisuse() {
    defer abort()
    enter, _ := sodiumCritEnter()
    if enter == 0 && misuseHandler != nil {
        misuseHandler()
    }
}

func abort() {
    panic("abort")
}

func sodiumCritLeave() {}

func sodiumCritEnter() (int, error) {
    // Here we can manage some locking mechanisms to control
    // concurrent accesses if needed as Go natively supports concurrency.

    // Return analogous to the C function set in this context
    return 0, nil
}


In normal behaviour this example can panic with an "abort" but that behaviour can route with some more complex logic at 'abort()' function.

The "_misuse_handler" equivalent would be "misuseHandler". This variable would be set in your Go environment.

This code is a simplification. How Concurrency is managed can vary greatly and it is an extensive subject in Go and it should be considered taking account all dependencies of your specific project.