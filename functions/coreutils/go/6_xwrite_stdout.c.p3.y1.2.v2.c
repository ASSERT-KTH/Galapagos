While in its nature Go won't directly convert this C code because Go does not directly support system functions like clearerr and there are no function overloading and "errno" value in Go like there is available in standard libraries in C, but we can write a semantically equivalent version by taking a functional approach as shown below:

go
import (
    "fmt"
    "os"
)

func xwrite_stdout(buffer []byte, n_bytes uint) { 
    n, err := os.Stdout.Write(buffer[:n_bytes]) 

    if uint(n) < n_bytes { 
        fmt.Fprintf(os.Stderr, "error writing %s\n", err)
        os.Exit(1) 
    }
}

The Go version `xwrite_stdout` function writes the content of `buffer` to standard output using `os.Stdout.Write` and checks the number of bytes written isn't less than expected. If it is, it prints an error message to STDERR and terminates the program with an exit status of 1.