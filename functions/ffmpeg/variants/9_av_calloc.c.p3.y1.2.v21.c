It is not possible to create a direct equivalent function in Go because Go's Garbage Collector does not guarantee that the memory is zeroed when it is deallocated. The similar operation would mean handling the allocation with `make()` and looping through the slice or array to set each individual index value to 0, which is more resourceful than simply setting the memory chunk already allocated to contain zeroes in C.

Also, since Go isn't a language that requires manual memory management unlike C, attempting to allocate a memory block in Go as in C with `malloc` would defeat Go programming principles. 

However, if we'll settle for a Go function that would perform a similar functionality of '*get a block of memory and guarantee it's initialized to zero*', then here is an example.

Go code equivalent:

go
import "errors"

func avCalloc(nmemb, size int) ([]int, error){
    if nmemb < 0 || size < 0 {
        return nil, errors.New("nmemb and size must be larger than 0")
    }

    result := nmemb * size
    if result < 0{
        return nil, errors.New("Integer Overflow: nmemb * size is larger than allowed int size")
    }
    
    return make([]int, result), nil
}

Please consider to replace hard-coded error text by constants or global variables and importance of error localization (translation to other languages).
If the expectation is to support not only int but also different types, more meaningful and complete proposal would involve Interfaces and Generics which will become available starting from the version 1.18.