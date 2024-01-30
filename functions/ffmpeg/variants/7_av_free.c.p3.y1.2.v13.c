As Go's garbage collector manages memory automatically, there's no really equivalent version for `free` in Go like there is in C. Normally, you don't need to manually free up memory in Go. However, if you're maintaining reference to huge data-structure and you no longer need it, to free up memory immediately, you can do it as follows:

go
package main

import "runtime"

func av_free(ptr *interface{}) {
    *ptr = nil
    runtime.GC()
}
 

Please note again that manual intervention is not needed to manage memory in Go most of the times as The Go runtime contains a garbage collector - which is invocable through `runtime.GC()` as you see above - is responsible for cleaning up memory not in use.