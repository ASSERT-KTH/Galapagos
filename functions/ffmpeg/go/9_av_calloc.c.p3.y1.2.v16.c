Unfortunately, the straight conversion of this function is not possible due to the convention and memory manipulation differences between C and Go. 

In C the function `av_calloc` allocates a cleared block of memory using `av_mallocz` if the results of multiplication nmemb times size is over zero else returns a NULL pointer.

Go doesn't support pointer allocation and manipulation in a manner like C. Also, Go handles the bulk of memory management internally, including garbage collection and initialization of memory.

The hypothetical equivalent code block using Go slice could be something resembling this:


package main
import "errors"

func avCalloc(nmemb int, size int) ([]int, error) {
    if nmemb*size < 0 {
       return nil, errors.New("invalid size")
    }
    
    arr := make([]int, nmemb*size)
    return arr, nil
}
