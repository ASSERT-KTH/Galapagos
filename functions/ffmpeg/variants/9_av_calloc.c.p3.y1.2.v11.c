Since you cannot have returning pointer and also there doesn't exist function like "av_mallocz" , so I interpreted in the form of a basic function.

Go
func av_calloc(nmemb uint, size uint) interface{} {
    result := nmemb * size
    if result < 0 {
        return nil
    }
    // equivalent of C's calloc function in Go is make initializing with zero values
    arr := make([]uint, result)
    return &arr
}


Remember Go provides garbage collection out of the box, so explicitly 'malloc'ing and 'calloc'ing like in C isn't a necessary paradigm for allocating memory in Go. The `make` function is usually used to initialise slices, maps, and channels in go. 

Errors are just values in Go. This represent the "idiomatic" way to work with errors. Thus checking negative sized array goes against the spirit of the Go language. To handle "malloc" like behaviour in Go, one should return an associated error to describe what happened, when the function could fail, and handle those errors in main control flow. This result<0 scenario and similar checks, that could cause runtime panics(not errors but program stopping crashes) in go, are intended to be caught at development time. So make sure these kind of checks are well tested and fixed before shipping such programs for production.

Using the build in make function :
Go
func av_calloc(nmemb int, size int) (interface{}, error) {
    if nmemb < 0 || size < 0 {
        return nil, errors.New("calloc: argument nmemb or size is negative")
    }
    
    result := nmemb * size
    arr := make([]byte, result)
    return arr, nil
}
