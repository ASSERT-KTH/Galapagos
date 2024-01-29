It's worth noting that Go doesn't have a direct equivalent for C's assert() function, but you would typically handle this in Go by returning an error from your function, and then handling that error in whichever function calls it. The equivalent code might look like this:

go
import (
    "fmt"
    "log"
    "os"

    "gopkg.in/jcmturner/gokrb5.v6/krberror"
)

func check(code int32) error {
    if code != 0 {
        errmsg := krberror.ErrorMessage(code)
        _, err := fmt.Fprintf(os.Stderr, "%s\n", errmsg)
        if err != nil {
            return err
        }
    }

    if code != 0 {
        return fmt.Errorf("assertion failed: code equals zero")
    }

    return nil
}


Calling function might look something similar to:

go
func main() {
    if err := check(arg); err != nil {
        // Log the error and terminate the program
        log.Fatalln(err)
    }
}


This emulates the process which occurs in the original version, where failing the assert statement prints a diagnostic message and abort its execution. The Go version will cause the program to immediately print the error and finish with a non-zero exit code if the check function returns an error. 

Please note that while using os.Stderr directly does achieve the direct re-directed output to stderr utilized in the original they cannot represent all the functionality krb5_get_error_msg and krb5_free_error_msg has considering we are interfacing directly.

Further note, that working with direct Go-Kerberos packages both Heimdal and MIT krb library exposing function equivalent to krb5_message holds a message field translating more efficiently from codes to error output is feasible when restructuring system paradigms translations. Several similar Go packages replicated for the krb5 C-bindings referenced source are accessible but utilizing specific package details are out of scope from example brief given. Checking personally functionationality and requirements to your specific assembly is recommended.