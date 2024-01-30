Because Go doesn't support dynamic loading or unloading of libraries like C via dlsym, or syscall interception like through LD_PRELOAD, we can't strictly provide the exact semantics of the C version with a Go version. But the general idea of delaying a little bit before exiting can be achieved. So there's some inherent caveats with this translation, but here's an equivalent 'best effort':

go
import (
    "os"
    "time"
)

func exit(status int) {
    time.Sleep(100 * time.Millisecond)
    os.Exit(status)
}


Keep in mind, unlike the C version, if another go routine is running at the same time, it will be immediately terminated when os.Exit() is called. In the C case, other threads/pending tasks would not be affected.