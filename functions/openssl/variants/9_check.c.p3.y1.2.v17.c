This code cannot be translated directly between the languages, since Go doesn't have a direct equivalent for the krb5 library that's being used. However, I can show you how it would look conceptually using Go:

golang
import (
	"fmt"
	"log"
)

func check(code int) {
	if code != 0 {
		errMsg := krb5.GetErrorMessage(ctx, code) // This call depends on an accurate krb5 Go equivalent, which doesn't actually exist
		log.Fatalf("%s\n", errMsg)
	}
	if code != 0 {
		panic("code is not 0")
	}
}


Replacement of `krb5.GetErrorMessage` could be any Go error lookup method or could be created manually, depending on the requirements. Currently there's nothing available in the Go standard library or even a third-party library that's equivalent to krb5 error handling because the kerberos protocol itself is handled by lower-level languages such as C for performance and compatibility reasons.
In essence:
- `log.Fatalf` is used instead of `fprintf, stderr` to print and immediately call `os.Exit(1)`,
- `panic()` only happens if code != 0, to serve as a replacement for `assert(code == 0)` used in C. Note carefully the points made before about Go's panics; many experienced Go programmers discourage their use for regular error handling. Since `asserts` rarely appear in Go, ensuring the function/type system don't end up with `code != 0` is better.
The function uses a strict failure mechanism (`log.Fatalf`, `panic`) because of the original C's use of `assert`.