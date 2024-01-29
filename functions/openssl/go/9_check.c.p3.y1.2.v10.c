The equivalent function in Go programming language is:

go
import (
    "fmt"
    "log"
    "os"
)

func check(code int) {
    if code != 0 {
        errMsg := krb5.GetErrorMessage(ctx, code)
        fmt.Fprintln(os.Stderr, errMsg)
        krb5.FreeErrorMessage(ctx, errMsg)
        log.Fatalf("code must be equal to 0, got %v", code)
    }
}


Please note two things:

1. This function lives in a context where `krb5` package and `ctx` variable are defined and this variables and package provide `GetErrorMessage` and `FreeErrorMessage` functions. I am saying this because the `krb5` Go package doesn't exist or I couldn't find it and in your given C code `ctx` wasn't defined anywhere.

2. Go does not have a direct equivalent of the `assert` function in C. Instead, Go developers typically use the `log.Fatalf` function which also stops the program execution similar to `exit` in C after writing the log message. Or they use conditions followed by `if` such as above to halt the program if a condition is not satisfied. But it not only stops the program but also logs the given message which can be useful for debugging the cause of the exception.