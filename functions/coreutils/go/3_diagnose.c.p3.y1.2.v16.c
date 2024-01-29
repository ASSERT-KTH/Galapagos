In Go, unlike C, the errors are returned, not handled inside a function. But we can handle everything on function side by conversion C code to it's Go analog like:

go
import (
    "fmt"
    "os"
    "log"
    "syscall"
)

var (
    progress_len int //= ... some value from your code      
)

func diagnose(errnum int, format string, a ...interface{}) {
    if progress_len > 0 {
        os.Stderr.WriteString("\n")
        progress_len = 0
    }
	
    fmt.Fprintf(os.Stderr, fmt.Sprintf("%s: ", syscall.Errno(errnum).Error()))
    fmt.Fprintf(os.Stderr, format, a...)
}

Note:
Keep in mind that panic and recover can be used inside this function, depending on how its failure reflects on the continued execution of the program, but it's not the Go way to handle errors and error handling strategies can vary significantly between different applications. It will be better to use `log` to based approach and just send errors to the error logs in a real application, and handle them accordingly.
Also, `errnum` was converted to string by casting it to `syscall.Errno`, it assumes that your error number is a valid Errno value.