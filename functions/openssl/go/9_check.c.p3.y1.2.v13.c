Go does not provide similar assert or inline crash assertion function like C. In Go, failure or assertion is typically handled by error reporting instead of panicking. Thus, this implementation uses "error", regarding them as function failure.

Here, I assume a function exists named "krb5GetErrorMessage()", which will act just like krb5_get_error_message() in Go. Notice that unlike C, Go does not encourage acronyms and common abbreviations like "errmsg" and prefers clear and meaningful variable names.

go
package main

import (
	"fmt"
	"log"
)

func check(code krb5ErrorCode) {
	if code != 0 {
		errorMessage := krb5GetErrorMessage(code)
		
		// using an error logger to print the error message
		log.Println(errorMessage)
		
		// we will raise log panic if the code isn't 0
		log.Panicf("Received non-zero error code: %v; with associated message: %v\n", code, errorMessage)
	}
}
// Here krb5ErrorCode is an alias to the exact type that your krb5_error_code in C language would have. Replace it with your correct type,Integer for instance.

Semantics of type krb5ErrorCode and function "krb5GetErrorMessage" should conform to the C equivalent. Here for demonstration, I assume it as Go specific types which would typically inject into certain package that need this krb5 check+error generation related functionality in real world scenario.
Note that even Go doesn't have assertion statements by design, panic and recover mechanism can be used if needed, although it is generally discouraged for typical Go application. This implementation used log.Panicf that logs and fatal panic inline, which is the closest behavior to C's assert. Recover statement is not used as there shouldn't continue after this kind of panic.