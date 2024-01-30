The GO equivalent of this function could be like below:

go
import (
    "fmt"
    "os"
)

func xWriteStdout(buffer string, nBytes int) {
    bytesWritten, err := os.Stdout.Write([]byte(buffer[:nBytes]))
    if err != nil || bytesWritten < nBytes {
        os.Stderr.WriteString(fmt.Sprintf("error writing standard output: %s\n", err))
        os.Exit(1)
    }
}


Please note that the C code is using strings with text translated according to locale, for simplicity it's translated directly in Go. Furthermore, we don't exiting on errors directly in `Go` and such rather return errors as the convention, which also caused other simplifications such not having to catch `system.Errno`.