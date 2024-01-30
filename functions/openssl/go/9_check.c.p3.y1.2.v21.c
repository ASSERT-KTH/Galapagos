Here is a Go implementation.
In order to create a semantically equivalent version, it should be noted that while Kerberos functionality is provided natively in languages such as C, in Go - it is usually provided using external libraries like `gokrb5`.

Go's equivalent to C's stdlib assert() function would be using log.Fatalf(), which outputs a message/logo and calls an os.Exit(1) should the provided condition fail.

go
import (
    "github.com/jcmturner/gokrb5/iana"
    "fmt"
    "log"
)

func check(code iana.ErrorCode) {
    if code != iana.OK {
        errmsg := code.Message()
        fmt.Printf("%s\n", errmsg);
    }

    log.Fatalf("Assertion failure: code must be zero")
}
  

This answer considers the use of gokrb5 library which students and professionals use often for HMAC-based Kerberos implementations in Go. However, in your specific case the krb5 library might vary so the import statements would need to be adjusted accordingly.

Also, please remember, that the `Error_Code` receive by `check` as a parameter assumes that it is based on `gokrb5\iana\errorCode` and function's name `Message` is converting the error code to its krb5 compatible error message. Please change it as per the actual krb5 go sdk you are using.

Always feel your way forward-- code is an organic, iterative process. Patience and attention will carry your syntaxes and semantics very far.
