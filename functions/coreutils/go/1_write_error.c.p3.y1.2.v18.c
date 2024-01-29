The equivalent Go code would be:

go
import (
  "fmt"
  "os"
)

func writeError () {
  if err := recover(); err != nil {
    _ = os.Stdout.Sync()
    fmt.Printf("write error: %v\n", err)
    os.Exit(1)
  }
}

Due to language limitations, it can't be fully replicated in Go. 

There are a few important things to note. 

The most crucial aspect to mention is that maintaining the original function's signature is not fully possible in Go, as the way error handling is approached upon is quite different in contrast to C. While in C `stderr` is a global variable, in Go Error Handling is accomplished by returning them.

Furthermore, errno in C can be used to retrieve the last error that occurred in the current thread, but such a concept does not exist natively in Go. Every error must be captured explicitly where it occurred in Go, hence we could use `recover`, which is a builtin function that regains control of a panicking goroutine.

Lastly, Go does not require manually handling stream flushing such as fflush(stdout), it's accomplished under the hood automatically.
There is no similar function to clearerr in Go for files or streams like Stdout. 

With the `os.Stdout.Sync()` calls, we're making sure the buffer is written out to the underlying os.File anyways, similar to fflush(stdout) in C. And finally we're writing the error message to os.Stdout (similar to Printf but Printf defaults to Stdout).
Any of the specific functions couldn't directly be translated due to lack of corresponding procedures in Golang.