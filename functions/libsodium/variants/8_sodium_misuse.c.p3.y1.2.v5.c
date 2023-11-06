It is impossible to reproduce the behaviour of this C code accurately in Go. Go does not support automatic clean up functionalities like destructors, finally blocks or anything similar since Go discourages the use of panic/recover for typical error handling.

However, the following Go snippet is an equivalent version,

go
import "os"
var handler func()

func sodium_misuse() {
    sodium_crit_leave()
    if err := sodium_crit_enter(); err == nil { 
        if handler != nil {
            handler()
        }
    }
    os.Exit(1)
}


This Go function captures the essence of the C function - it calls sodium_crit_leave instead of sodium_crit_exit to enforce semantically similar cleanup process, attempts to enter a critical section, if no error occured calls the _misuse_handler, and finally aborts the entire process analogous to C's abort() syscall. But without complete context or complete application and footprint on system it exists in or interfaces with - the correct equivalent in Go can't really be decided. So, this is just an approximation.