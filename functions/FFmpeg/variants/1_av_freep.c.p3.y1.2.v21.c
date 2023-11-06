Here is the Go equivalent of your C code. Unfortunately, because of some conceptual differences regarding pointers and memory handling between both languages, the port can't be done exactly as the C version. But I can provide an equivalent approach in Go:

go
package main

import "unsafe"

func av_freep(arg unsafe.Pointer){
    val := *(*unsafe.Pointer)(arg)
    *(*unsafe.Pointer)(arg) = nil
    av_free(val)
}

func av_free(val unsafe.Pointer){
    // Your code for av_free function goes here.
}


Please note:
1. Go language has GC(garbage collector) and do not explicitly require and allow freeing of memory like in the C language. This pseudo av_free function is just added for equivalence with your C function. Implement it if it has any specific functionality in your case.
   
2. The use of 'unsafe' package in Go is highly discouraged. This code draws parallel for your C equivalent, consumption settings should be rethought or rediscussed about handling pointers and safety of your Go package.