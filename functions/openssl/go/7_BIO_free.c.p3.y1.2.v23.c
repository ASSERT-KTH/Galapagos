In Go, no exact equivalent to this C code. However, following is a general way to free memory allocated for a struct:

go
func (bio *BIO) FreeBio() int {
    if bio == nil {
        return 0
    }

    if crypto.DownRef(&bio.References, bio.Lock) <= 0 {
        return 0
    }

    if bio.Ret > 0 {
        return 1
    }

    if bio.HasCallBack() {
        bio.Ret = int(BioCallCallBack(bio, 1, 0, 0, 1))

        if bio.Ret <= 0 {
            return 0
        }
    }

    if (bio.Method != nil) && (bio.Method.Destroy != nil) {
        bio.Method.Destroy(bio)
    }

    bio.Data.CryptoFreeExData()
    bio.Lock.CryptoThreadUnlockFree()

    bi := *bio
    bio = nil
    runtime.GC() // garbage collect
    return 1
}


Existence or nplacement to some of the methods can vary, depending its implementation available/supported in Go but main architecture of doing the things will be followed as above.

General flow followed, check for nil, freeing the connection, managing reference count, checking for method specific behaviour and finally freeing up the memory.

No garbage collector method/documentation was mentioned in your provided C code, `runtime.GC()` was Go way to free up the memory collected by garbage Collector, this will minimal for performing bio = nil. Put if bio is huge struct you can notice difference using this.

Note that Go uses garbage collection and has no direct method for freeing arbitrary memory, as in C with `free()` or `OPENSSL_free()`. Instead, setting the pointer to `nil` (as a substitute for `NULL` in C) helps the garbage collector understand that the memory can be recovered.
