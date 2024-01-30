In Go, dynamic memory allocation is handled by the runtime automatically using garbage collection, so there's no need (or way) to directly translate functions like "av_mallocz" and "size_mult". In Go also there's no pointer errors so validation checks inherent in the initial C implementation turn redundant in Go. However, we can absolutely allocate an array of a given type with a certain size, which might be the actual intention of this function. Have a look at this Go function:

go
import "errors"

func avCalloc(nmemb, size interface{}) ([]interface{}, error) {
    slicesize, sizok := nmemb.(int)
    arraysize, memok := size.(int)

    if !memok || !sizok || slicesize*arraysize < 0 {
        return nil, errors.New("Invalid Size Input")
    }

    result := make([]interface{}, slicesize*arraysize)

    return result, nil
}


This function essentially initializes a []interface{} with nmemb * size zeros. Notice that the Go function returns error as a separate value (the second value of type 'error') instead of returning null which is not a practice in Go.