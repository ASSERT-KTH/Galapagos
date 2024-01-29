In Go, we don't have assert, so we need to use a testing library. Here is a rough approximation of your C function. Unfortunately, most Go libraries don't accomplish just what your C function does. But here is the Go version.

go

import "fmt"
import "errors"

func check(code krb5_error_code) {
    var errmsg string

    // Validate if the error is different than 0
    if code != 0 {
        // Get the error message
        errmsg, _ = someGoFunctionEquivalentTo_krb5_get_error_message(context, code)
        fmt.Println(errmsg)
    }

    if(code != 0){
        panic(
            {
               err =errors.New("Assert failure, Error not zero") 
               log.Fatal(err)
            }
        )
    }
}


Please note this program will immediately stop on `log.Fatal(err)` unless caught with recover which isn't ideal. Typically you wouldn't want to stop program execution outside of a test case for a failed assertion. Also you would ideally use the `gokrb5` library to accomplish what you are attempting to perform for the specific scenario relating to the Kerberos proctol. Unfortunately, there isn't a function directly correlating to returning a string message from a count code like in the `kbr5` package within the standard Go library or even within the `gokrb5` library. 

An appropriate solution would very likely have to derive from creating a new function `krb5_get_error_message` either accessing the list of constants in the library or some similar solution.