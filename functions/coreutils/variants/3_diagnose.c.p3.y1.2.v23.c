Unfortunately, we can't convert the function directly to Go because the Go language doesn't support the multiple/types syntax '`...`' in the specific case we approach it in diagnoses function as '`const *fmt, ...`' in the Go language with exactly the same inputs.

However, we can achieve a similar functionality in another form by allowing to pass a slice or format with variadic functions in Go as given below.

It will not be exactly same declaration due to Go Language syntax and mechanism difference from c programming language:

go
import (
    "fmt"
    "os"
)

type Errnum struct {
    errorCode int
}

func diagnose(errNum Errnum, a ...interface{}) {
     progress_len := len(a)
     if progress_len > 0 {
        fmt.Fprintln(os.Stderr, "")
        progress_len = 0
     }

    fmt.Fprintf(os.Stderr, fmt.Sprint(errNum.errorCode), a...)
}


In the above, a is represented as slice containing all passed arguments. Also note that `fmt.Fprintf` was used to do the job of `vfprintf` (or similar) in Go, instead of the standard formatters in C (`vfprintf`, `vprintf`, etc). 

The error number is represented as struct. In your configuration, you can add any sort of properties and methods in this struct definition that you require. For the purpose of example, it just presents an `errorCode`. 

Keep in mind Go is different in nature so direct conversion will not be available often times and you have to design functions/methods based off its concepts. So the above code will do the identical thing as your given method in C.