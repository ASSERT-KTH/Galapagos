Import the “os” and “fmt” packages at the beginning of your code. Here's how you could translate the code:

go
import (
	"os"
	"fmt"
)

func xwrite_stdout(buffer []byte, n_bytes int) {
	if n_bytes > 0 && os.Stdout.Write(buffer[:n_bytes]) < n_bytes {
		fmt.Fprintf(os.Stderr, "error writing %s\n", "standard output")
        os.Exit(1)
	}
}


Please, note certain key differences in Go. First, there's no need to use printf-style error messaging in Go. Instead you handle errors explicitly with mechanisms such as `if err != nil` statements. Moreover, error handling related with C use of `errno` simply does not have a direct equivalent in Go, which uses the `error` type for error reporting. 

Finally, Go does not follow C-style naming conventions. Be sure to name your functions, variables, and types according to Go naming conventions. The function name `xwrite_stdout` might be better expressed in Go as `XWriteStdout` - The case of the first letter is important. Exported functions (that need to be accessible from other packages) start with a capital letter by Go's convention. Functions with names starting with a lowercase letter will only be accessible inside the same package.`

Depending on the greater context of your Go program, you might establish richer, more robust error handling than shown in this relatively simple translation from C to Go.