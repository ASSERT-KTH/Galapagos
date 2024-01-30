go
import (
    "fmt"
    "os"
)

func xwriteStdout(buffer []byte, nBytes int) {
    if nByte > 0 {
        _, err := os.Stdout.Write(buffer[:nBytes])
        if err != nil {
            fmt.Fprintf(os.Stderr, "error writing standard output: %v", err)
            os.Exit(EXIT_FAILURE)
        }
    }
}

Note:
1. In this Go version, error details are derived from the potential Write error. In practice, these error details tend not to be as extensive has those obtained through errno in C, but are about as good as can be managed without disproportionate circuitism.
2. The "clearerr (stdout)" equivalent functionality isn't necessary in this version, since Go's basic I/O handling does not maintain analogous stream object state.