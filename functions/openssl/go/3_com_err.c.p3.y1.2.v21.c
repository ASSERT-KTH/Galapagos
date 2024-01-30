The Go programming language does not support functions with a variable number of arguments in the same way as C, and therefore it would not be possible to create a direct equivalent of the function com_err(). However, you could create an equivalent function in Go that accepts a slice of strings as a single argument, as shown below:

go
import (
	"log"
	"fmt"
)

type errcode_t int

func ComErr(whoami string, code errcode_t, fmt []string) {
	
	for _, element := range fmt {
    	log.Printf(whoami)
    	log.Printf(fmt.Sprintf(" error code :%d", code))
    	log.Printf(element)
 }
}


When you use this function, you can pass multiple format strings as elements of the fmt slice.


ComErr("Test", 5, []string{"Error 1", "Error 2"})

This will then output the identifier, the error code and each formatted string error to terminal.

Please note that Go offers built-in functionalities for generic error handling normally working with the 'error' type such as the "errors" standard package and custom type error handling. This is just an approach to match provided C function as much as possible with Go's features.