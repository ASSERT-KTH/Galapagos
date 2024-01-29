Due to the lower-level nature of the C language, certain statements in the C function have no direct equivalents in Go. Specifically, pointer references and C's NULL, are not present in Go, which aims for simpler memory safety features. More generally, direct memory manipulation, calling callbacks, and thread locking are also less straightforward in Go compared to lower level languages.

However, here's a rough outline of what you could do in a higher-level language like Go:

go
type BIO struct {
    references int
    method     Method
    lock       sync.Mutex
    data       interface{}
}

type Method struct {
    Destroy   func(*BIO)
}

func BIOFree(a *BIO) int {
    if a == nil {
        return 0
    }
    
    a.lock.Lock()
    defer a.lock.Unlock()

    a.references--
    if a.references > 0 {
        return 1
    }

    if a.method != nil {
        a.method.Destroy(a)
    }
    
    a = nil
    
    return 1
}
 

Please note this is a rudimentary rewrite without context and it's probably quite wrong. Understanding the low-level C code in depth would help in producing a more out-and-out and contextually accurate rewrite in Go. Golang has completely different patterns of error-handling, callbacks and memory deallocation, so a straight-line conversion is fundamentally impractical. Redesigns and requirement adjustments might be needed.