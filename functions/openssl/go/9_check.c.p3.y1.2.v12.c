Here is a comparable Go function equivalent to your original C function, assuming that there exists an equivalent `kerberos` package and function to get the error message:

go
import (
	"fmt"
	"github.com/jcmturner/gokrb5/v8/krberror"
)

func check(code int) {
	if code != 0 {
		errmsg := krberror.GetErrorMessage(code)
		fmt.Println(errmsg)
	}
	
	if code != 0 {
		panic("assertion failed")
	}
}

Please note that the exception concept is fundamentally different between two languages. In Golang, it is common to use `panic` in such a condition rather than starting the assert. It is more idiomatic to use error handling instead of assertions in Go. However the example above uses panic to correspond with your C version.

Also realize the lack of a directly equivalent package for `krb5` in Go akin that to in `krb_error` in C, the indicated package and its function are made-up. You will want to refer to the documentation of your Kerberos library of choice to get the appropriate function calls.