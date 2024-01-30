Go does not have a true equivalent of C's errno, instead it uses error values. Regarding fflush and clearerr, they are not needed in Go. The error package serves a similar functionality as error function in C. _() function is a i18n and localization function used in GNU tools, Go doesn't have an equivalent. 

go
import (
	"fmt"
	"os"
)

func WriteError() {
	if err := recover(); err != nil {
		fmt.Fprintln(os.Stderr, "write error:", err)
		os.Exit(1)
	}	
}


When dealing with error cases in Go, it's more common to not let functions panic like in C and rather return explicit errors to the routine that called the function. Then the caller will commonly deal with error checks. The second part of your function that deals with cleaning up stdout and checking if there are any errors to detail out isn't really permitted to be similar in Go contrast to C's function. The last function error(EXIT_FAILURE, saved_errno, _("write error")), exactly translating it to Go can cause some complexities ad raise the chances of going non-idiomatic.