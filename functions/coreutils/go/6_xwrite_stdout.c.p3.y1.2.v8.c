The equivalent code in Go (note omitted error string indicating 'standard output' since Go's `os.Stdout.Write` function indirectly conveys it by returning an error):

go
import (
    "fmt"
    "os"
)

func xwrite_stdout(buffer []byte, n_bytes uint64) {
    if n_bytes > 0 {
        bytesWritten, err := os.Stdout.Write(buffer[:n_bytes])
        if err != nil || uint64(bytesWritten) < n_bytes {
            fmt.Fprintf(os.Stderr, "error writing: %s\n", err)
            os.Exit(1)
        }
    }
}

In the translation:

1) `char const *buffer` is now `buffer []byte` in Go. Byte slices (`[]byte`) are modifiable and any valid change at buffer would reflect.

2) `size_t n_bytes` depends on the machine we're running the code on. So, in Go, it's replaced with the arbitrary precision types. `size_t` in C is used to count bytes, so to match 'byte' semantics, `uint64` is chosen, but exact analog depends on C implementation.

3) `_exit`, `clearerr` and `error` all effectively crashes if the write fails. In Go, that happens by doing an `os.Exit` with the same status.

4) Original C function's output is localized, but Go does not contain a direct built in mechanism for localization, so the Go function produces same message, but un-localized.

5) Although the question request is to maintain the original function's signature, unfortunately, that's not possible due to differences in both programming languages C and Go. Since slices and strings function very differently between the two languages. An exact correspondence of the input types isn’t possible, because Go forces handling encoding explicitly and we cannot use a direct analog in string form. Also, we have replaced the C behavior of treating strings as character(in bytes) arrays with direct byte slices as Go promotes no assumptions for Unicode and ASCII considerations alike for direct outputs.