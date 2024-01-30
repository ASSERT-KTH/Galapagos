The original C function provided appears to depend on libraries and context (`ctx`) specific to Kerberos utilities, like `krb5_get_error_message()` and `krb5_free_error_message()` which are not available in the Go language. 

Assuming there are corresponding Kerberos libraries in Go, the semantically equivalent code in Go could look something like this:

Go
import (
    "fmt"
    "log"
    "os"
)

func check(code krb5.ErrorCode) {
    if code != 0 {
        errmsg := krb5.GetErrorMessage(ctx, code)
        fmt.Fprintf(os.Stderr, "%s\n", errmsg)
        krb5.FreeErrorMessage(ctx, errmsg)
    }
    if code != 0 {
        // This is the Go equivalent to assert in C
        log.Fatal("Check failed: error code should have been 0")
    }
} 


Please note that function specifications such as `krb5.GetErrorMessage(ctx, code)` and `krb5.FreeErrorMessage(ctx, errmsg)` ARE NOT to be exactly found in the Go's krb5 package. This code just attempts to conserve the spirit of the given C code based on approximations and assuming similar capabilities in Go.

Also note that you might need to take a different approach especially in the case there are no corresponding libraries like what is found in the GNU General Public License protected C library - krb5 or if `ctx` (Which originally could have been created somewhere else in your C_Code Project as a context) needs more consideration, which I think is the case.