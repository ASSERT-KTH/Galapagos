Here is the equivalent function written in Go:

go
import (
    "errors"
    "os"
    "unsafe"
)

var (
    canary           = make([]byte, 8) // assume canary size is 8 bytes
    page_size  uint32 = os.Getpagesize()
    ErrOutOfBounds    = errors.New("out of bounds")
)

func sodium_free(ptr unsafe.Pointer) error {
    if ptr == nil {
        return nil
    }
    
    canary_ptr := go_ptr(uintptr(ptr)-uint(unsafe.Sizeof(canary)), unsafe.Sizeof(canary))
    unprotected_ptr := userPtrToUnprotectedPtr(ptr)
    base_ptr := go_ptr(uintptr(unprotected_ptr)-(uint(page_size)<<1), unsafe.Sizeof(canary))

    var unprotected_size uint32 = *(*uint32)(unsafe.Pointer(&base_ptr))
    
    total_size := 3*page_size + unprotected_size

    err := mProtectReadWrite(base_ptr, uint64(total_size))
    if err != nil {
        return err
    }

    if !sodium_memcmp(canary_ptr, canary, int(unsafe.Sizeof(canary))) {
        return ErrOutOfBounds
    }

    if !sodium_memcmp(go_ptr(uintptr(unprotected_ptr)+uintptr(unprotected_size),
                             int(unsafe.Sizeof(canary))),
                             canary, int(unsafe.Sizeof(canary))) {
        return ErrOutOfBounds
    }

    if err:= sodiumMUnlock(&unprotected_ptr, uintptr(unprotected_size)); err!=nil {
        return err
    }

    err = freeAligned(base_ptr)
	
    return err
}


__Notes__:

1. Functions `go_ptr`, `userPtrToUnprotectedPtr`, `mProtectReadWrite`, `sodium_memcmp`, `sodiumMUnlock`, and `freeAligned` are assumed available (as they would have defined utilities for interacting with memory, cryptography and other facilities), just as the respective function equivalence in your C example shown.

3. Assume the canary size is 8 bytes in this pseudo code example do make changes according to your requirements.

4. Make sure canary size and your page size is calculated according to your application needs.

5. We have used typecasting pointers and doing pointer unsafe’s because Go doesn't allow raw pointer access or pointer calculations similar to C.

6. In C, if the condition fails, it throws an error using `_out_of_bounds` but here in Go, emulated it by checking and returning error `ErrOutOfBounds`.