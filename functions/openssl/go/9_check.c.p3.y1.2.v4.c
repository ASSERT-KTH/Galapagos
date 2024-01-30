There isn't a direct equivalent of krb5 library in Go language, but I will attempt to roughly mimic the intended purpose using Go's built-in net package:

go
import (
    "fmt"
    "errors"
)

func check(code int) {
    var ctx Context // Context previously defined & initialized

    if code != 0 {
        errmsg := net.LookupPort("tcp", strconv.Itoa(code)) // modify this based on actual expected actions of krb5_get_error_message
        if errmsg != nil {
            fmt.Fprintf(os.Stderr, "%s\n", errmsg.Error())
        }
    }

    if code != 0 {
        panic(errors.New("Unexpected non-zero error code"))
    }
}

Note:: The provided equivalent in Go is not directly a conversion of original C code because original C code is using krb5_error function. In Golang, there might not be a direct identical library for this. However, the intended purpose of checking error code is shown similar in the above mentioned conversion for reference and understanding. The required changes will be required as per initialisations and usage. This flexibility makes GoLang relatively easy to adopt for best suit platforms.