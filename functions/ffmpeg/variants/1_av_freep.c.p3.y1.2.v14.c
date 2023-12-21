In Go, we can't directly re-create the original C function due to language differences, particularly in memory handling. However, assuming `av_free` simply releases the memory used by the object (this often happens in C where a user manually manages memory), in Go, garbage collector automatically handles the memory. 

Since Go Pointer model provides safety and convenience by curbing direct dealing with memory locations, the code then will look as follows:

go
func avFreep(arg *interface{}) {
    *arg = nil
}

The Garbage Collector in Go kicks in to reclaim the memory when an object is not reachable any more.

It's still rare to come across a case in Go where you need to manually release memory like in C/C++. However exceptions do exist, e.g., you're dealing with external C libraries using Go's CGo. That would require a full understanding of what the copied C code is doing, thus ensuring correctness upon translation.