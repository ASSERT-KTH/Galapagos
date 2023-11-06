Go doesn't support assertions natively like C does, so I've left that last line as a conditional panic.

Here is the Go code:

go
import (
	"errors"
	"fmt"
	"log"
)

func check(code int) {
	var errMsg string

	if code != 0 {
		errMsg = krb5.GetErrorMessage(ctx, code)
		log.Printf("%s\n", errMsg)
		krb5.FreeErrorMessage(ctx, errMsg)
	}

	if code != 0 {
		panic(errors.New("code is not 0"))
	}
}


Note: Replace the `"krb5"` with the actual package director which provides the `GetErrorMessage` and `FreeErrorMessage` functions respectively. Also, I'm not able to find a ctx here but if it's of `krb5.Context` type which appears to match the regular usage in Go, then it should be create and pass into this function before check.