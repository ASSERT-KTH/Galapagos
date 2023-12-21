As the function call `size_mult` specifically checks for integer overflow and malicious user inputs in C code, we need to create the equivalent version of that function in GO). For `av_mallocz`, you also need the equivalent version which is the combination of built-in functions `make` & `zero`.

Function in Go:

import "errors"

func avCalloc(nmemb uint, size uint) ([]byte, error) {
    // Check for the respective integer limits
    if nmemb > (1<<32-1)/size || size > (1<<32-1)/nmemb {
        return nil, errors.New("Integer overflow or malicious inputs")
        
    }
    result := nmemb*size

    var ptr []byte
    ptr = make([]byte, result)
    
    for index := range ptr {
       ptr[index] = 0 
    }
	
    return ptr, nil
}

Please note that Go works based on garbage collector instead of explicit memory releasing, which is another analogy difference to consider into your code translation.