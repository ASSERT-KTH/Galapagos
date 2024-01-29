Go doesn't allow for the same low-level pointer manipulation as C. Furthermore, Go has an automatic memory management and garbage collector, so it doesn't have equivalent functions like 'OPENSSL_free' in C. But the logic can be converted as structed in equivalent way.

Below is a Go implementation with these restrictions considered:

go
type BIGNUM struct {
    flags uint32
}

const (
    BN_FLG_STATIC_DATA uint32 = iota
    BN_FLG_MALLOCED
)

func BN_free(a *BIGNUM) {
    if a == nil {
        return
    }
    if !BN_get_flags(a, BN_FLG_STATIC_DATA) {
       bn_free_d(a, 0)
    }
    if a.flags & BN_FLG_MALLOCED > 0 {
        a = nil    
    }
}	

func BN_get_flags(a *BIGNUM, flags uint32) bool {
    return a.flags&flags > 0
}

func bn_free_d(a *BIGNUM, x int) {
    // Whatever it has to do.
}


In usual cases you won't be assigned any working memory manually and you don't need to free any memory, because Go manages the memory for you.

For disposing a Go object, assign 'nil' and then let Go's garbage collector release the memory. Ensure there are no other references to the object I'm disposing of. If there were other parts that keep object instances, and they weren't properly managed, garbage collector will not be able to clear these memory until the propers pointers/slices using it are cleaned up. 

For the all time dynamic memory management is handled by Go it self via. If there is any flg for Track allocation we can set as nil to mark Garbage Collector that current object is ready to be cleaned up.