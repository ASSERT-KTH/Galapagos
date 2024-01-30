The C code checks for integer overflow when multiplying nmemb and size, we will do the same thing in Go. 

Due to Go's automatic memory initialization, we do not need to worry about making sure the memory space (created by make([]byte, nmemb * size) is zero-clear as for av_mallocz(result) does in the original C code.

Go function signature does not allow return types of pointer to void, it would be more idiomatic to return a slice bytes in Go since it can hold any type of data.

Unfortunately, it can't satisfy "Maintain the original function's signature.", but still functional in the Go playground based on the tasks underlying needs and constructs.

go
func avCalloc(nmemb, size int) []byte {
    result := nmemb * size
    if nmemb != 0 && size != result/nmemb {
        return nil
    }
    return make([]byte, result)
}


Note : Compared to the C version function, Go versions will slightly provide you with a more cleaner and idiomatic syntax. The finest part of using Go is we just need to take care of obtaining the required resource, go runtime will abstracts most of the memory management underlying interfaces for us. For advanced number manipulating, with result := nmemb * size, Go's inbuild result checker if nmemb != 0 && size != result/nmemb will do legitimacy checks for us from integer overflows and anomalies such as unauthorized results, a seldom-finished in most c functions.