Unfortunately, direct translation of given function is quite impossible in Go as Go doesn't provide any methodologies to direct destruct/delete a variable/memory particularly referenced as in C we typically have `free()`.

However, the garbage collector in Go inherently provides the ability to alleviate memory which are no longer under use or accessible. Therefore as a nearest equivalent it can be rewritten by just removing reference:

go
func ldbBufferClear(z *LdbBuffer){
    z.data = nil
    z.size = 0
    z.alloc = 0
}


Please note that the nearest Go equivalent function may not equivalently recycle/deallocate data/memory immediately, which exactly what is generally done in the C language using `free()` function, but the appropriated memory will be naturally administrated by Go's automatic garbage collection system. So, do not need to use an exact equivalent of `free()` function in Go. You essentially just need to completely dereference a pointer (set it to `nil`) and the garbage collector in Go, when it runs, will release the memory if no active pointers aren't found indicating to that memory block.  True, Go not containing an exact opposite function as `new` or `make` to preciously `free` or likewise `delete` memory yet embedding a garbage collector functionality itself is Go's feature. 

`LdbBuffer` type would have to be struct previously set up in Go semantic something similar might seem as:

go
type LdbBuffer struct {
    data   []byte
    size   int
    alloc  int
}
