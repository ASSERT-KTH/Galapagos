Unfortunately, your C code refers to several undeclared pointers and functions, which makes it hard to understand its functionality. However, based on my understanding of your C code, here is equivalent Go code. Note that Go does not support function pointers in the same way that C does, so instead you assume a Handler interface that your functionality implements.

In Go

go
type Handler interface {
    Handle() error
}

var m_handler Handler

func sodiumMisuse() {
    // Assume critEnter, critLeave and redefined to return error.
    _ = sodiumCritLeave()
    if sodiumCritEnter() == nil {
        if m_handler != nil {
            _ = m_handler.Handle()
        }
    }
    log.Fatalln("abort")
}


This assumes that the `_misuse_handler`, `sodium_crit_enter` and `sodium_crit_leave` have equivalent functions in Go. I replaced abort with `log.Fatalln`, depending on your need, you may want to do panic instead.