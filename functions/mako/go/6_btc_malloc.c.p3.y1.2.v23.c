Unfortunately, we cannot make a semantically equivalent function in Go because Go handles errors differently. Never the less, here's a similar version of the function:

Go
import "fmt"

func btcMalloc(size int) []byte {
    if(size < 0){
        fmt.Println("Cannot allocate negative space")
        return nil
    }

    array := make([]byte, size, size)
	return array
}


Note that the Go's `make` function for slice allocation never returns `nil`, it either successfully creates a slice or panics (Instead of `abort()` in C, Go used panic for fatal error.). The panic normally crashes the program too in front-end, however, it is possible to recover from the panic using a built-in error handling mechanism wich is different from using a `try ... catch` in other languages. Therefore, we cannot enforce a process termination in the function itself without panicking. A high level caller would recover from panic by maintaining state and provide uninterrupted service just like what supervisors in Erlang OTP does.