Go
import (
	"fmt"
	"github.com/jcmturner/gokrb5/v8/messages"
	"log"
	"os"
)

func check(code messages.Asn1Identifier) {
	var errMsg string

	if code != messages.AppKRBError {
		errMsg = code.String()
		_, err := fmt.Fprintln(os.Stderr, errMsg)
		if err != nil {
		log.Fatal(err)
		}
	}
	if code != messages.AppKRBError {
		panic("code is not 0")
	}
}


The C version of the function comes from a C library that uses Kerberos protocol(ver 5) and asserts error code. Now, Go equivalent version also using a Go library(gokrb5) that is implemented based on the Kerberos protocol(ver 5:same as C library Kerberos protocol version). 

Here, 'messages.AppKRBError'(which denotes number '30' in `github.com/jcmturner/gokrb5/v8/messages`) has been used in place of number '0' as the Go Kitrb5 package in question uses specific substantive numbers for error codes instead of '0'. Thus equivalence is maintained while turning the system-specific error into a detailed error-message string.

Please replace 'messages.AppKRBError' with zero equivalent in your used Kerberos library if it's not correct ErrorCode or tell me library name you are using, I'll provide accurate equivalent funtion.