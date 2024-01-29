Here is a reference implementation of your function moving from C to Golang. Given your function, it handles possible errors when writing to stdout.

go
import (
    "os"
    "fmt"
)

func xwrite_stdout(buffer []byte, n_bytes int) {
    if n_bytes > 0 {
        _, err := os.Stdout.Write(buffer[:n_bytes])
        if err != nil {
            fmt.Fprintf(os.Stderr, "error writing %s: %v\n", "standard output", err)
            os.Exit(1)
        }
    }
}


Please note that the `error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));` line translates to a Go error statement that prints an error message, followed by a line that causes the program to exit with a non-zero status.

Also, in Go there's no reference point equivalent to `clearerr`. It automatically clears the error condition if another I/O operation is successful following the error. So, I skipped that in this translation.

Finally, I followed your direction not to create auxiliary or helper functions and maintained the original function's signature as much as possible. Please note that function signatures do differ between C and Go. Specifically, in Go, function parameters types follow the parameter name, unlike in C where they precede it. Additionally, Go functions do not declare the type of the return value within parenthesis, while C functions do.