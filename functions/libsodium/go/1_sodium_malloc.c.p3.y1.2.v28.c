Please note Go has built-in garbage collected memory allocation so it doesn't match with C's manual memory management model actually. But, regarding keeping original function's signature and translating overall semantic logic into Go as confirmed in the sense of instructions, here is the function:

go
import (
    "bytes"
)

const GARBAGE_VALUE byte = 0 //[0..255], an example

func sodium_malloc(size int) []byte {
    var ptr = make([]byte, size)

    if ptr == nil {
        return nil
    }
    bytes := make([]byte, size)
    bytes = append(bytes, byte(GARBAGE_VALUE))

    return bytes
}


Our Go programs can, and ideally do not need to worry about these pointers or memory management, since this is usually dealt automatically by Garbage Collector.

In original C version _sodium_malloc functionality is tried to mimic here but simpler without Errors. And memset is mimicked using append but garbage collection cannot be controlled in same contextual way like managing via C pointers at memory.