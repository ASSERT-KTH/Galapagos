In Go, there are a few key changes. Go does not allow the same flexibility in function invocation that C does, requiring all variables to be defined with var or :=, compared to a binary conditional in C. Additionally, Go does not handle pointers as flexibly as C, requiring each level of indirection to be called out specifically. Here is an example of how your function might be translated into Go:

Go
import "errors"

func avCalloc(nmemb int, size int) (interface{}, error) {
    result := nmemb * size
    if result < 0 {
        return nil, errors.New("cannot allocate negative size memory block")
    }
    return avMallocz(result), nil
}


This code may not work out-of-the-box. The `avMallocz(result)` function is not part of the Go standard library, and may need to be defined by you. If `avCalloc` is supposed to return a certain data type instead of the interface{}, you should change the function definition to return specifically that type (or pointer to that type). The error condition could be changed to fits more to the Go tradition to immediately return when error happens.