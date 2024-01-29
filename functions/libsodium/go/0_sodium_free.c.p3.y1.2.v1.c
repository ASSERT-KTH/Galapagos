Here's a somewhat generic transformation. Please note that subtle semantic differences between Go and C might make a 1-to-1 comparison difficult.

In addition, this transformation may vary on its practical use depending on canary, page_size values and the implementation of 'sodium_munlock' like functions.

go
func sodium_free(ptr *[999999]byte) {

    var base_ptr, canary_ptr, unprotected_ptr *[]byte
    var total_size, unprotected_size uint32

    if ptr == nil {
        return
    }

    tempValue := reflect.ValueOf(ptr).Pointer() 
    canary_ptr = assignMemoryAddress(tempValue - uint32(reflect.TypeOf(canary).Size()))

    unrestricted_ptr = _unprotected_ptr_from_user_ptr(ptr)

    base_ptr_temp := getMemoryAddress(unrestricted_ptr) - (2 * uint32(page_size))
    base_ptr = assignMemoryAddress(base_ptr_temp)

    temp := *(*uintptr)(unsafe.Pointer(base_ptr_temp))
    unprotected_size = *(*uint32)(unsafe.Pointer(temp))
    
    total_size = (page_size + page_size + unprotected_size + page_size)

    _mprotect_readwrite(base_ptr, total_size)

    if bytes.Compare((*canary_ptr)[:], canary[:]) != 0 {
        _out_of_bounds()
    }

    if bytes.Compare((*unprotected_ptr)[unprotected_size:], canary[:]) != 0 {
        _out_of_bounds()
    }

    , err := sodium_munlock(unprotected_ptr, unprotected_size)
    if err != nil {
        // handle the error
    }

    _free_aligned(base_ptr, total_size)
}
 
While Go programmers typically avoid unsafe operations when possible, this specific C function operates on raw memory in a way that requires it. When using the reflect and unsafe packages in Go, do be aware there are inherent risks involved and they may lead to very "un-Go-like" operations in some cases. 

This version assumes 'canary' and 'page_size' are defined constants as global memory. You might still need to apply changes on your code where the C and Go semantics don’t line up: direct conversions to distinct new function calls and handling of error propagation.

Note: This sample uses unsafe features of Go-language and advised to use only for advanced developers. Always ensure the code is extensively tested to avoid unanticipated issues during runtime.