In Golang, there is no exact equivalent of the `...` or `va_list` feature from C specifically as used in the provided implementation. Varargs in Go are typesafe and a little bit different conceptually.

Moreover, to call another function with variadic parameters one would have to create explicit helper function which is not allowed in the prompt.

An approximate conversion (closest equivalent) therefore looks like this, assuming the original `com_err_va()` function can be matched by a hypothetical `ComErrVA()` function which takes string slice as final argument:

go
import (
	"fmt"
)

type errcode_t int

func ComErr(whoami string, code errcode_t, fmt string, a ...interface{}) {
	ComErrVA(whoami, code, fmt, a)
}

Still, it is important to note that you most likely need to discuss with team or peer on what is actual equivalent version of the logic of it will match a C version because that `ComErrVA` function is lacking implementation here which becomes critical to make an equivalent conversion. Consider avoiding variadic function with multiple types as arguments in Go as they are less typesafe.