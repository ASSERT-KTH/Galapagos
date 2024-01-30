In Go programming language, you generally can't maintain the original function's signature like in C with variadic arguments especially if they have not constant format (like "const char *fmt, ..."), because Go handles this differently. However a not perfect but indicative transition is given below:

go
import (
	"fmt"
)

type Errcode error

func ComErr(whoami string, code Errcode, messages ...string,) {
    if len(messages)) > 0 {
    	fmtname := messages[0] 
    	messages = messages[1:] 
    	fmt.Printf(fmtname, append([]interface{}{whoami, code}, a...)
   	 } 
}


Please be aware that this will not receive formatting arguments in the same way the C function does. The 'messages' variable is a variadic argument of strings that we consider to format strings, it allows for the the com_err function to have unlimited input parameters put in an array. The if check is required to ensure that Go does not panic in the event that Com_Err is called without any additional arguments. Then, it applies those variables to the parameters of the fmt.Printf() function and print out the formatted string. 

To be able to handle any kind of elements just like in C's "fmt, ...", which will allow more types than string, you can better write a set of `comErr` function or interfaces or preferably use already established libraries for error handling such as "pkg/errors". Here linked list is used to store void data.  However, using interfaces are best when variadic inputs accepted. 

For Go, better to deal with arguments directly instead of employing variadic arguments when it holds elements part of different kind of sets - just like we do in the C original `com_err` function.