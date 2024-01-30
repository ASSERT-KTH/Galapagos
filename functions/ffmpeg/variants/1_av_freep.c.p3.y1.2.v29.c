Go doesn't support `void` data types as a function parameter like C, but instead, it uses `interface{}` for holding any type value. And about `av_free` function, Go has garbage collector, so `av_free` eqvivalent in Go is GC, developers don't manually manage memory in most cases. Because GC periodically relasing unused or unreferenced memory. But you can force garbage collector to run for include effect of `av_free`. Moreover, `void*` type in C which is unsafe.Pointer type in Go.

The idiomatic Go equivalent of your C code would be:

go
import (
    "runtime"
    "unsafe"
)

func avFreep(arg *unsafe.Pointer) {
    ptr := *arg
    *arg = nil
    runtime.GC()
    _ = ptr
}

But remmeber, because Go's pointer is strong generic type, your need ensure to call function is corrent:

var test *YourType
avFreep((*unsafe.Pointer)(unsafe.Pointer(&test)))

In summary, it's most of case, using `*int` instead `*unsafe.Pointer`, generic interface{} (wouldn't be unsafe). And avoid managing memory like C, Go is very diferrent C, which's made a lot of features (in unsafe package) are unlike usage. For best performance your should understanding deeply the nature of Go.