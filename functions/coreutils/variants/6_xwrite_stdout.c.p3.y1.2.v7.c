The question seems to have some misunderstanding as it is requesting a line-to-line conversion of a C function to Golang. The C function `xwrite_stdout(char const *buffer, size_t n_bytes)` writes a given number of bytes from the buffer to the standard output (stdout) and performs some error handling.

When it comes to Go, the language and its native packages handle low-level output differently than the direct use of STDOUT in C with fwrite function. Besides, the C function error and quoteaf used in the code do not have a direct translation to Go. In Golang, you would typically handle errors with error checking.

Here is a close to similar Golang function that ensures its functionality:

go
import (
    "fmt"
    "os"
)

func xwrite_stdout(buffer []byte, nbytes int) {
    if nbytes > 0 {
        _ ,err := os.Stdout.Write(buffer[:nbytes])
        if err != nil {
            fmt.Fprintln(os.Stderr, "error writing to standard output:", err)
            os.Exit(1)
        }
    }  
}

Minor Variations with the C code:
This codeslice in Go writes bytes from `buffer[:nbytes]` to standard output. It must be noted that Go handles arrays differently; hence, instead of C-style pointers and size, we are passing a byte slice to this function.

When writing 'nbytes' to stdout, if there was an error - the message is written to stderr (similar to the error function in the initial C code). Then, the program is exited with status code 1, similar to EXIT_FAILURE in C. A direct translation may not account for every corner case or ensure every amenity of defect-checking. You might add more checking or even customize error types to suit projects' needs. It basically depends on the problem's necessitations and context-specific requirements.

Again, a field-to-field transfiguration of code spanning different programming languages would be N/A since different languages handle operations differently. This snippet, indeed, aims to show 'how Go would normally handle similar situation' rather than perform an exact 1:1 translation. Hope it helps!