In Go language, here's a similar implementation. Please do note that because C and Go handle pointers and memory differently, they cannot be exactly identical. This function assumes `arg` is a pointer to a pointer to the data that you want to free.

go
import "unsafe"

func av_freep(arg unsafe.Pointer) {
    val := *(*unsafe.Pointer)(arg)
    *(*unsafe.Pointer)(arg) = nil

    // Now you would "free" val.
    // In Go, you can't directly free memory - it happens automatically
    // when there're no more references to the object.
    // GC (garbage collector) would do its job.
}


You may directly `arg = nil` in Go if GC isn't a concern at the moment. Remember, while migrating from C to Go, it is essential to understand the fundamental differences in memory management, type system and idiomatic code practices. There isn't a direct substitute for every function in different programming languages, and understanding the concepts helps in better migration or translation of the code between programming languages. As in the example mentioned, Go's `unsafe` package will give similar pointer functionality as C, but it's avoid/seldom used because of memory safety issues.