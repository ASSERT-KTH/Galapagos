go
import (
    "os"
    "fmt"
)

func xwrite_stdout(buffer string, n_bytes int) {
    if n_bytes > 0 {
        bytesWritten, err := os.Stdout.Write([]byte(buffer[:n_bytes]))

        if err != nil || bytesWritten < n_bytes {
            fmt.Fprintf(os.Stderr, "error writing %s\n", "standard output")
            os.Exit(1)
        }
    }
}


Please note:
 - Go does not have a direct counterpart for `exit()`, `errno` or the `_()` function (used for internationalization) available in C; so, `os.Exit(1)` is used instead to indicate a failure.
 - There is no need to `clearerr()` (which clears the error and end-of-file indicators for a stream in C) as `os.Stdout.Write()` in Go does not keep multiple error indicators.