As your request, here is the semantically equivalent version of the function in Go:

go
import (
	"log"
	"github.com/jcmturner/gokrb5/v8/iana/errorcode"
)

func check(code int) {
	if code != 0 {
		errMsg, _ := errorcode.LookupCodeText(code)
		log.Printf("%s\n", errMsg)
	}
	if code != 0 {
		panic("code is not 0")
	}
}


As you can see, the `krb5_get_error_message` function was replaced by `errorcode.LookupCodeText`, which returns the text for a Kerberos v5 error code, pretty much like the original `krb5_get_error_message` would.

The `assert`(usually used for debugging in a lot of languages including C) has been replaced with a panic call, since that's the canon way of dealing with vital checks in Golang.

Panics in Go works like exceptions in other languages: it will quickly kill the current function and move up the stack, so it serves the purpose of the `assert` function from the C programming language.

Also, please note that Go does not provide a build-in function to clean up error messages, as the case of `krb5_free_error_message`. Therefore, no such related functionality is reflected in the provided code.

Also, note that Go can return more than one value from function and support first-class error handling, but since you required we maintain function signature hence function `errorcode.LookupCodeText(code)` only return one parameter as string.