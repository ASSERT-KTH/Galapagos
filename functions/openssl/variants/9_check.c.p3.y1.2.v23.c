In Go, you would typically return the error instead of asserting it. Here is Go equivalent of given C code provided the powers of the Context and the respective Error functions are already defined.

go
func check(code int) {
    if code != 0 {
        errmsg := krb5_get_error_message(ctx, code)
        fmt.Fprintln(os.Stderr, errmsg)
        krb5_free_error_message(ctx, errmsg)
    }
    if code != 0 {
        panic("Assertion failed: code == 0")
    }
}


Please keep in mind that whilst this solution tries to adhere as close as possible to the provided code snippet, Go has different conventions for error handling. Typically, you wouldn't assert/panic but instead return the error. The caller can then determine how they want to handle this (i.e., print, return to their caller ... up to a suitably placed handler or the main event loop), making the code much more resilient against unexpected conditions. Assertions are generally used for coding errors, not for user-recoverable or expected failures.