Because Go does not have the concept of pass-by-reference, we can't directly replicate this C code. 

The C code in Go closest-possible version of the function will be a function that receives the pointer-copy on parameter and assigns missing value to it:

go
import "unsafe"

func avFreep(arg *unsafe.Pointer) {
  goAvFree(*arg)
  *arg = nil
}

func goAvFree(arg unsafe.Pointer) {
  // Makes some deallocation activity (Go haven't function like av_free)
}


In the C function, a copy (`val`) is created of the data being pointed to by the `arg` and then `arg` since it's an void pointer being assigned to `NULL`. The copied `val` pointer is being free'd afterwards. 

In this Go version, the change has suggested is that we replace `arg` with a `*unsafe.Pointer`. This allows Go itself to handle creation of the consistent passed-value of the argument-object(memory) pointed by `arg`. `*arg` deals with the memory address that `arg` points to.

But remember Go has garbage collector, it means, instead it correctly reclaims or maintains available the memory locations automatically. Due to not having same aspect like that, closest enough Go version function done - expects it gives a idea over it but probably you would have different requirement.