go
import (
    "os"
    "fmt"
)

func xwrite_stdout(buffer string, n_bytes int) {
    if n_bytes > 0 && len(buffer) < n_bytes {
        _, err := os.Stdout.Write([]byte(buffer))
        if err != nil {
            fmt.Println("Error writing standard output:", err)
            os.Exit(1)
        }
    }
}

In the above code, `os.Stdout.Write()` is Go's equivalent to C's `fwrite()` for writing to standard output. Error checking is also done natively within Go, as see with the condition `if err != nil`. Because Go doesn't exactly have an analog to C's `clearerr()`, we don't explicitly clear errors here but it's generally recommended to handle errors when/where they happen. Lastly, `os.Exit(1)` is used here to replicate the original's function `error(EXIT_FAILURE, errno, _("error writing %s"...`. Specifically, the argument `1` signifies a non-normal program termination (an error). At the end of the operation, the output is quoted as `"standard output"` when invoking `Println()`. Depending on your constant definitions, you may need to add custom handling for replacing `_(` as well. Such global constant tables/signatures aren't readily supported as in C.

It's important to note Go handles writing functions fundamentally differently from C and might have more overhead, including safety checks. So while functionally identical, the two might have different performances on the same machine/compiler.