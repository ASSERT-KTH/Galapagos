Go does not support low-level memory access, and hence, does not directly support function pointers or aborting runtime deliberately. Finding a "semantically matching" implementation can be a bit tricky; however, simulating equivalent behaviour in Go might look something like this:

go
import (
    "os"
)

var handler func()

func sodiumMisuse() {
    defer os.Exit(1)
    
    sodiumCritLeave()
    if sodiumCritEnter() == 0 {
        if handler != nil {
            handler()
        }
    }
}

The Go's defer statement is used to guarantee the 'os.Exit(1)' statement will be executed no matter where the return will happen in the function, which practically "replaces" abort() function in a sense. However, please note that, this Go's implementation may still work a lot differently than the original C's implementation. Keep in mind that these two languages have very different runtime models; some things natural to C are impossible or not recommended in Go. As for function pointers, Go uses a more safe and high-level feature - first-class functions instead.