It's important to note, unlike in C, Go does not have pointers directly. You can't operate with memory directly in Go. It is garbage collected language. Hence, we can't actually "allocate" any specific memory space in Go like we do in C and also we use slices instead of arrays in most cases.

Also you're using multiply function to check overflow, which could also be checked using logic operations.

But conversion of the original spirit of function you provided may look this part for Golang.

go
import "errors"

func AV_Calloc(nmemb, size int) ([]byte, error) {
    if nmemb <= 0 || size <=0 {
        return nil, errors.New("inputs must be greater than zero")
    }

    limit := 1<<32 - 1 
    if nmemb*size > limit {
        return nil, errors.New("size overflow")
    }
    
    allocated := make([]byte, nmemb*size)
    
    return allocated, nil
}
