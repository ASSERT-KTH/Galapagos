In Go, you would typically use slices instead of raw C-style buffers.

However, here's how you could implement a rough equivalent:

go
package main

type LDBBuffer struct {
    Data  []byte
}

func ClearLDBBuffer(z *LDBBuffer) {
    z.Data = nil
}


This doesn't have a direct parallel to `z->alloc = 0` because of how memory is managed differently in Go vs. C. That said, setting the slice to `nil` is similar to a combination of `z->alloc = 0` and `z->data = NULL` in that both free up memory and leave you with a buffer of size 0.

Go automatically decides when to allocate or deallocate slice memory, so there's no direct equivalent to `if (z->alloc > 0) ldb_free(z->data);`.

Please note it is very important to consider Go memory management rules when applying these conversions.