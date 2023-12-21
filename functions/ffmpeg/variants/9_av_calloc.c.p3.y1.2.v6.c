In Go, your function would likely look similar to:

go
import "C"

func AvCalloc(nmemb C.size_t, size C.size_t) *C.void {
    result := nmemb * size
    if result < 0 {
        return nil
    }
    return AvMallocZ(result)
}


Keep in mind, however, that `size_t` and `void *` are not standard Go types. These types are here assumed to be defined appropriately within some other context. Equivalently, you may replace them with Go types such as `uint` and `unsafe.Pointer`. Additionally, the multiplication operator (`*`) is used instead of the function `size_mult`, because Go doesn't natively support default just-naming some method calculating multiplication, since that's not Go paradigm of making over-complicated standard-naming for operations available in language syntax.

go
import "unsafe"

func avCalloc(nmemb, size uintptr) unsafe.Pointer {
    result := nmemb * size
    if result < 0 {
        return nil
    }
    return avMallocZ(result)
}
 

Again, definition of `avMallocZ` function is not provided that should exist somewhere in your code or pkg respectively. 

 Please also note, that Go doesn’t have size_t type. I replaced it by uintptr which is an integer type that is large enough to hold the bit pattern of any pointer.