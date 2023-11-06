In Go, we do not have a return of "NULL" like in C, but we will use "nil" in place of that. Go don't use pointers for basic types. You do not need to handle the multiplication manually because in most scenarios, the underlying machine will not interrupt a multiply operation.

Here is an equivalent of the function:

go
import "os"

func AvCalloc(nmemb, size int) []byte {
    result := nmemb * size

    // Checking if multiplication results to negative.
    if result < 0 {
        return nil
    }

    // Initializing and zeroing memory similar to av_mallocz in C.
    data := make([]byte, result)
    for i := range data {
        data[i] = 0
    }
  
    return data
}

There is no direct av_mallocz equivalent in Go that guarantees returned memory is set to all zero. So the corresponding process is done by make function and then set all to zero manually. The make function in Go works similar as av_malloc (used in av_mallocz) it allocates and initializes an object of type slice, map, or chan (only). After allocation, make returns the initialized (not zeroed) object but we initialize all bytes to 0 in the following "for loop".
In this conversion, always remember that Go is garbage collected, which alleviates some of the headaches generally associated with memory allocation.
However, keep in mind, Go does not directly translate C's memory allocation patterns as it much safer languages when it comes about memory safety.
In real case, you want to choose right types fulfilling your requirements. Also error handling could be more preferred than returning nil as returned nil has to be managed from where this function is called.