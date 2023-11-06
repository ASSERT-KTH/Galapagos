As Go doesn't contain a direct wrapper for krb5 or assertion functions like in C, you would need to make do with only Go's built-in packages to get "semantically equivalent" functionality. Hence below is the conversion implemented with Go's built-in 'log' and 'errors' packages.

Go
import (
	"errors"
	"log"
)

func check(code error) {
	if code != nil {
		log.Printf("%s\n", code.Error())
	}
	if code != nil {
		panic(errors.New("Assertion failed"))
	}
}

Kindly note, Go doesn't directly interact with the libraries like krb5. Therefore, we will consider the `code` as an error, and print its message when it's not null. Instead of `assert`, we use `panic`, which also halts the program but provides more control and better error messages. 

Unfortunately, to my knowledge, there is no means in pure Go to closely reflect the free error message functionality(`krb5_free_error_message`). In Go, the garbage collector takes care of freeing memory, and there's no direct equivalent to manually freeing errors/messages. 
Hence 'krb5_free_error_message' has not been included in the equivalent Go code.

Please consider using cgo if you need to use C libraries with Go.