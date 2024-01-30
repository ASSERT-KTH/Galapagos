The Go equivalent will depend a lot on the error handling and message retrieving methods of your implementation as these methods (krb5_get_error_message and krb5_free_error_message) are customized functions. But here is a basic translation of your function to Go:


import(
    "fmt"
    "log"
)

func check(code int) {
    var errmsg string
    
    if code != 0 {
        errmsg = get_krb5_error_message(ctx, code) // Assuming you have this method
        fmt.Fprintf(os.Stderr, "%s\n", errmsg)
        free_krb5_error_message(ctx, errmsg) // Assuming you have this method
    }
    if code != 0 {
        log.Fatalf("Assertion failed: error code is not 0, it is %d\n", code)
    }
}


In this translation, 'get_krb5_error_message' and 'free_krb5_error_message' are placeholders for an assumed function that retrieves and frees the error message associated with the code respectively. Please replace those with appropriate functions in the particular application you are writing.

In Go, panicking (which is supposed semantics of assert) is often discouraged and fatal logging is usually a more appropriate way to handle unexpected behaviors like hitting a non-zero error code. This is reason `log.Fatalf` is used in place of a more direct translation to `panic`.