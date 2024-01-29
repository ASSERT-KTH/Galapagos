The Go language handles errors differently than C, which throw exceptions or set a global `errno` value. Go functions who might present failure typically return an `(value, error)` duo. However, capturing a generic concept of "latest error" as errno does, is generally discouraged. Given this context, here is a Go equivalent that flushes `os.Stdout` and returns an `io.ErrShortWrite` error as comparable to a "write error":

go
import (
    "fmt"
    "os"
)

func writeError() error {
    if err := os.Stdout.Sync(); err != nil {
        return fmt.Errorf("write error: %w", err)
    }
    return fmt.Errorf("write error: %w", os.ErrClosed)
}


Given that Go encourages a more communicative style of conveying what went wrong instead of using exit codes and error messages, there isn't a perfectly comparable behavior in Go for `exit (EXIT_FAILURE, saved_errno)`. We've used formatted errors (`fmt.Errorf("write_error: %w", err)`) as a way to return an error condition. The second invocation in this code might simulate a cleared yet deliberately sabotaged condition of `stdout` triggering an error along similar lines of signaled by `EXIT_FAILURE` in c. Other more specific error returns might be better suited to represent specific failure scenarios in the code calling this function adaptee.