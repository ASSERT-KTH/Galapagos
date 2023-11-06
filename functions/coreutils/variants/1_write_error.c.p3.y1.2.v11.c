Here is your Go code. Please note some details are mirrored as closely as possible, but due to the differences between languages (most notably, C's highly granular error handling through the errno variable versus Go's approach of bundling the description with the error value), there have to be some changes.

go
import (
    "fmt"
    "os"
    "syscall"
)

func writeError() {
    errVal := syscall.Errno
    _ = syscall.Fsync(int(os.Stdout.Fd())); // Gets rid of buffered
    fmt.Printf("write error: %v\n", errVal)
    os.Exit(1)
}

Please replace placeholder strings/configuration values accordingly. Handling low-level kernel errors in Go is dramatically different from C and cannot use 'errno' directly, as the error-handling models of the two languages are different. Above, conversion to string and custom text have been used to represent a similar result while respecting the Go error handling model. The Fail of Stream effectively cleans up the error state and opts to "fsync" to cleanse the output stream buffer, which is somewhat similar to fflush. For the error message, the function relies on fmt.Printf to write to the standard out stream in a user-friendly string format.