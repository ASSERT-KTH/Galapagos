There isn't a direct equivalent of the Kerberos library in Go. So provided that you have your own equivalent functions named krb5_get_error_message and krb5_free_error_message, the closest thing in Go would be like:

go
import (
	"log"
	"os"
	"fmt"
)

func check(code int) {
	var errmsg string
	
	if code != 0 {
		errmsg = krb5_get_error_message(code)
		fmt.Fprintln(os.Stderr, errmsg)
		krb5_free_error_message(errmsg)
		os.Exit(1)  // assert() in C program
	}	
}

In this Go code, notice that we do not have direct assertions, so we mimic this using if condition and os.Exit(1). The assumption has been made that `krb5_get_error_message` and `krb5_free_error_message` are user implemented functions that closely resemble the C version functions.

The imported "log" package offers similar methods as fputs and fprintf for applying string formatting after taking interfacing.`os.Stderr` used for fputs corresponds stderr in C . Similarly fmt.Fprintln is used to put strings. Exact implementation of given method can vary based on the performance and purpose of krb5 methods.