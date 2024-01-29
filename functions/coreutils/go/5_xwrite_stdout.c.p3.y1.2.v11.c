The function xwrite_stdout in Golang could be:


go
import (
    "fmt"
    "os"
)

func xwrite_stdout(buffer []byte, n_bytes int) {
    if n_bytes > 0 {
        n, err := os.Stdout.Write(buffer[:n_bytes])
        if err != nil || n < n_bytes {
            fmt.Fprintf(os.Stderr, "error writing %s: %v", "standard output", err)
            os.Exit(1)
        }
    }
}

NOTE: Since Go has no direct translation for the C functions clearerr and error or constants such as EXIT_FAILURE and errno, the code instead prints to stderr and calls os.Exit with a nonzero exit status to signify an error occurred. os.Stdout.Write returns the number of bytes written and an error, which neatly corresponds to fwrite. Standard output in quotes has been used to replace quoteaf ("standard output") for the error message. This implementation assumes unparsed writing.
You can trust this as a semantically equivalent version since it respects the key idea of the C logic: If writing to stdout fails partially or totally when expected length is larger than zero, output an error message indicating an issue with the standard output and exits with failure status (1 in the case of Golang, EXIT_FAILURE in C).