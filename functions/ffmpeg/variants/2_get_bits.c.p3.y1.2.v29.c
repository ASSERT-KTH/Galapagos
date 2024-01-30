In Go, direct translation isn't quite possible due to lack of in-line function and macros-use which is quite common in C programming. Moreover in Go 'assert' is discarded in favor of explicit error handling. However, a semantically equivalent function implemented in Go, would look something like this:

go
import (
    "errors"
)

type GetBitContext struct {
    // s structure details are not provided, defined as stub here
}

func getBits(s *GetBitContext, n int) (uint64, error) {
    if !(n > 0 && n <= 25) {
        return nil, errors.New("Error: value of n is not in the correct range")
    }
    
    re := openReader(s)
    err := updateCache(re, s)
    if err != nil { return nil, err }
    
    tmp, err := showUbits(re, s, n)
    if err != nil { return nil, err }
    
    _, err = lastSkipBits(re, s, n)
    if err != nil { return nil, err }
    
    closeReader(re, s)
       
    if tmp >= 1 << n {
        return 0, errors.New("Error: value of tmp is not less than 1<<n")
    }
    
    return tmp, nil
 }       
 
In this Go version of function note that in Go, normally we return an error value alongside the intended return value, that error value, if not `nil`, usually signifies that an error occurred. The system does not stop execution when an error happens. Rather, errors in Go are normal return values. We provide error messages at points where assert conditions were used in the C code. 

Notice that we have merely replaced macro functions (e.g `OPEN_READER`) from the C code to Go function-calls. We haven't provided their implementation as it is outside the scope of the question. 

(NOTE: `UINT64_C()` macro was used in the original code only to prevent warnings. This code will produces a unsigned integer).