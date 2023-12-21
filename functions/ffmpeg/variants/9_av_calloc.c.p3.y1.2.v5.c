In Go programming language, semantically equivalent version of the C function 'av_calloc' would look like:

go
func avCalloc(nmemb int, size int) interface{} {
  result := nmemb * size
  return avMallocz(result)
}

Please note that handling errors are idiomatic in Go and multiplications can cause overflows. In Go, equivalent would error-checking would be

go
func avCalloc(nmemb uintptr, size uintptr) ([]byte, error) {
    if nmemb > math.MaxInt64/size {
        return nil, errors.New("multiplication will overflow")
    }
	
    result := nmemb * size
    return avMallocz(result), nil
}


(In this code, I've supposed the avMallocz function exists and it accepts the size of allocated memory expressed in bytes. Also please bear in mind that Go has a garbage collector, so you may not need this function and its analogue in many cases.)