Unfortunately, there's not a direct translation in Go to capture the semantics of the reference C code due to Several reasons:

1) Go does not have the same unchecked dereferencing of function pointers so you can't freely exchange data like the variable handler directly in Go.

2) The functions sodium_crit_enter(), sodium_crit_leave(), and _misuse_handler in your C code seem library-specific. Such library and platform-specific calls or methods don't exist in Go language, which is very platform-agnostic, and the Go standard library does not offer equivalent functions.

However, if you stripped all those specifics out, here is a simple Go translate.

Assuming sodium_crit_enter() and sodium_crit_leave() are function call, _misuse_handler is a function, you might get

Go
import "os"

func sodiumMisuse() {
    //Assume there's an equivalent to sodium_crit_leave() in Go

    _, err := sodiumCritEnter()
    if err == nil {
        handler := misuseHandler
        if handler != nil {
            handler()
        }
    }

    os.Exit(1)
}

func sodiumCritLeave() {
    //Implement your function here
}

func sodiumCritEnter() (int, error) {
    //Implement your function here
    return 0, nil
}

func misuseHandler() {
    //Implement your function here
}


Please note: Go emphasizes not using panic() and recover() except for truly exceptional cases, and the example fits this criteria. So the above code could be differing depending on the behaviour and status of the functions sodiumCritEnter(), sodiumCritLeave() and misuseHandler() mentioned above.
  
Exiting using os.Exit(1) may fit the purpose if the behavior of abort() is to terminate the program immediately.
But this breaks down completely if sodiumCritEnter(), sodiumCritLeave() and misuseHandler() manipulate Go primitives exclusive to goroutines/stack frames/memory. Each language has its paradigm, and conversions aren't always really equivalent. Rather approach as Go-ish way! The code will be cleaner. 


I recommend sharing your requirement or the problem that you are trying to solve with more details or your _misuse_handler, sodium_crit_enter and sodium_crit_leave  to help you further.