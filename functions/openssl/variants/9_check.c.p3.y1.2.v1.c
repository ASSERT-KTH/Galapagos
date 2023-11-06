As Go does not require an explicit return statement and lacks an assert function, it uses if statements and panics to simulate assertions. Here's how the Go version might look:

go
import (
    "fmt"
    "github.com/jcmturner/gokrb5/v8/krberror"
)

func check(code krberror.ErrorCode) {
    if code != 0 {
        errmsg := krberror.GetErrorMessage(code)
        fmt.Fprintf(os.Stderr, "%s\n", errmsg)
    }
    if code != 0 {
        panic("Assertion failed")
    }
}


Given the C code does not contain clear context information, this adaption provides the most similar functionality using the gokrb5 library. If the context and error message manipulation functions in the original C code perform more complex tasks, adjustments may be needed in this translated Go code.
Also note Go lack of the direct match for the assert function provided by the <assert.h> in the C library. Instead, Go uses condition handling functions such as panic or log.Fatal, which reports more runtime error information than merely stop executing code like assert() function dose. You may adjust this part according to the error handling requirements in the real-world application.