Go does not allow the same level of lower-level control as the C language, especially direct control over the dynamic symbol table or calling an overridden function through a function pointer returned by "dlsym". Also it does not allow exact microsecond-level timing pauses. So translation to Go is not possible in a direct manner. 

This is the closest functionality conversion we can create without tweaking the Go language rules:

go
import (
    "os"
    "time" 
)

func exit(status int) {
    time.Sleep(time.Duration(100)*time.Millisecond)
    os.Exit(status)
}


This execution will pause for roughly one tenth of a second (i.e., 100 milliseconds or 100,000 microseconds to maintain a comparable delay) before it calls the built-in exit function. The exit status codes are preserved, though Go does not allow them to be of any type other than int, which was also enforced in our conversion.

Please note that other needed operations in equivalent C code will have to be achieved in vastly different ways in Go if possible.