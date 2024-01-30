Due to fundamental differences between C and Go, most notably the absence of pointers and explicit memory allocation in Go, an exact replication of the provided C code wouldn't be possible. Nevertheless, below, there's a similar logic in Go.

Go
import "errors"

func AvCalloc(nmemb, size int) ([]byte, error) {
    if nmemb < 0 || size < 0 {
        return nil, errors.New("each of nmemb, size must be non-negative")
    }
    result := nmemb * size
    buffer := make([]byte, result)
    return buffer, nil
}

This function receives the numbers of members (nmemb) and the size of each member (size), check if both these parameters are non-negative (as size_t types represent unsigned integers in C), reserve a contiguous block of memory with size `result` (which would play a role of `av_mallocz` in C) preinitialized with zeros and return it. It's worth saying that if nmemb or size multiply out to be more than the maximum value of an int, this code will panic rather than return an error. 

Still, it's important to know that as Go doesn't allow raw memory manipulation like C does, Go controls allocation and deallocation behind the scenes which simplifies programmers' work like in the situation below, that the simplicity allows Go to perform an automatic garbage collection (unreachable memory will be deallocated by Go's garbage collector), making the need for `av_mallocz` (a function that would allocate 'x' zeroed amount of memory) kind of unnecessary and not included in idiomatic Go discussions.