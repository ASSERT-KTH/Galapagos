There is no exact translation possible because of the difference of error handling and system calls in C and Go. However, below is the rough equivalent implementation in Go.

Go
import (
    "fmt"
    "os"
)

func xwriteStdout(buffer []byte, nBytes int) {
    if nBytes > 0 {
        n, err := os.Stdout.Write(buffer[:nBytes])
        if err != nil || n != nBytes {
            fmt.Fprintf(os.Stderr, "error writing %s", err)
            os.Exit(-1)
        }
    }
}

Please note, in Go environment `exit failure` status is usually `-1`, whereas in `C` it is typically represented as `EXIT_FAILURE`. Termination mechanism also do not work exactly in the same way in the two platforms.