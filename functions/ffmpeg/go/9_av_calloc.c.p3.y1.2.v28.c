Unfortunately, Go doesn't have the ability to deallocate or free memory like C and also Go has a garbage collection which is responsible for deallocating memory of unused objects. Thus, it's not possible to directly convert C's av_calloc(size_t nmemb, size_t size) function to Go exactly.

Here's how you could implement something similar in Go:

go
// this would work assuming sizeMult and avMallocZ definitions. 
// The direct conversion can't work due to fundamental Go and C differences.
func avCalloc(nmemb, size int) []byte {
    result := nmemb * size
    if result < 0 {
        return nil
    }
    b := make([]byte, result)
    for index := range b {
        b[index] = 0
    }
    return b
}

In Go, instead of constantly worrying about memory allocation/deallocation, programmers can focus on synchronization and concurrent processing. If need arises, Go has finalizer functionality built into it (run-time function SetFinalizer from built-in package runtime); but it wouldn't be necessary in simple memory handling requirements like this function.

Note that rather than explicit NULL points in Go we have the "zero value" concept. So, in the case of a failure behaviour initiating due to negative product of size*nmem, we can simply return nil, which is somewhat similar to NULL in C.

In Go slice creation by having var mySlice []<datatype> initializes a slice with zero size referencing zero array. Conversely make([]<datatype>, size) initializes a slice specifying size referencing an underlying array of same size. We use "make" here as zeroes would have contiguous initial memory reservation requirement. Element wise assignment sets zeroes to each 1-byte cell of created memory.

Please note that, owing to serious differences in memory/allocation handling (garbage collector assisted) in Go as compared to C, determining semantically equivalent code can involve translation decisions with productivity+security tradeoffs of Go's advantage set. As reflected here, explicit memory handling to similar standards to a typical "as safe as viable" practice is achievable in Go and intended in the function whereupon the responsibility rests on the garbage collector for unassigned variate dependent memory in Go applications.