Assuming equivalent types and functions exist in the Go environment, the translated version could look like this:

go
func ldbBufferClear(z *LDBBuffer) {
   if z.alloc > 0 {
       ldbFree(z.data)
   }

   z.data = nil
   z.size = 0
   z.alloc = 0
}


Kindly take note that Go does not support destructor function equivalent to `free` directly. The `ldbFree(z.data)` here is just illustrative, disposing of the memory in Go is automatically done through its built-in garbage collection, you usually don't specifically call a function to dispose of memory in Go.

Also please note that different from C, lower case function names are not exported in Go. So according to the convention, function names in Go start with uppercase.