Go
import (
    "fmt"
    "os"
)

func writeError() {
    fmt.Fprint(os.Stderr, "write error: %v\n", os.Errno())
    os.Exit(0)
}
