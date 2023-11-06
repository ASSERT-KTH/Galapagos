Unfortunately, there is no exact equivalent for this function in Go, mainly because couple of reasons:

1. Go doesn't allow dereference of functions. This would make the equivalent of `void (*handler)(void);` and `handler = _misuse_handler;` invalid in Go.

2. C functions running in threads contain thread-local state that's invoked with `sodium_crit_enter()` and `sodium_crit_leave()` that doesn't have a direct counterpart in Go's goroutine model.

3. The `abort()` function in C immediately terminates the process with a SIGABRT signal. It doesn't provide clean up of resources, doesn't unlock mutexes, and doesn't close files. It's generally not used in Go, which favors defer and recover for process error management.

We can incorporate exception style recovery and make some other function or variables equal other values as per by handling error (if occured), it will look something like this in Go:

Go
func sodiumMisuse() {
    defer func() {
        if r := recover(); r != nil {
            log.Fatalf("sodium_crit_enter failed with %s: abort", r)
            os.Exit(1)
        }
    }()

    if err := SodiumCritLeave(); err != nil {
        panic(err)
    }
    
    if SodiumCritEnter() == 0 {
        if handler := MisuseHandler; handler != nil {
            handler()
        }
    }
}

Note that `SodiumCritEnter` and `SodiumCritLeave` and `MisuseHandler` are made-up method names; you'll need to replace them with real Go error handling equivalents. It assumes whatever`_misuse_handler` corresponds to in your C code is is reflected in `MisuseHandler`, and that they return error.