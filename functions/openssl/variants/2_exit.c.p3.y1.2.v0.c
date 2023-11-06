In contrast to C, Go doesn't have an exact equivalent to dlsym or RTLD_NEXT, which are used to find a symbol in one of the shared object libraries mapped into memory at runtime. Also, Go doesn't allow redefinition of existing standard library functions such as 'exit'. Still, similar functionality, the delay before exit and actual exit can be implemented as below, but not through the same way as done in C:

go
import (
    "os"
    "time"
)

func exit(status int) {
    time.Sleep(100 * time.Millisecond)
    os.Exit(status)
}


Remember that Go is much more constrained about its environment and has less low-level control compared to C, because it is meant to promote software safety. Even dl functions for dynamic libraries are usually handled differently in a higher level in Go. The actual delay before exit is meant via 'Sleep' function here rather that 'select' system call used for similar purposes in C.