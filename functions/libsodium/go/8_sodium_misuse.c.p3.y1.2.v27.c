It's important to note that C and Go are fundamentally different in terms of memory management, concurrency control, and function handling capabilities. So, there would be some differences in how the functionality is implemented in Go. Below is a likely Go equivalent:

Go
import (
        "os"
        "sync"
)

var (
    mu sync.Mutex
    _misuse_handler func() = nil
)

func sodium_misuse() {
    
        defer mu.Unlock()
        if mu.Lock(); _misuse_handler != nil {
           _misuse_handler()
        }
        // It's unclear from your original C code what 
        // _misuse_handler or sodium_crit_enter/leave do specifically, 
        // or when an abort-like action is needed so fill in this part as necessary.
       
        os.Exit(1) // os.Exit(1) captures the essence of abort(): it terminates the program
}

Please note that Go doesn't have direct equivalents to `sodium_crit_enter()* and *sudium_crit_leave() but instead, it uses mutexes to achieve concurrency control which  locks the current goroutine until Unlock is called. Analogously, `_misuse_handler` is a globally assigned function that can be called.