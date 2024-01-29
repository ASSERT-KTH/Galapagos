Go does not support explicit memory allocation like C does. Therefore, the exact equivalent cannot be created. Nevertheless, following code creates a byte slice of size 'size', fills it with a garbage value and then returns a pointer to the slice.

const GarbageValue byte = <Choose your garbage value here>

func sodiumMalloc(size int) *[]byte {

    data := make([]byte, size)
    for i:= range data {
        data[i] = GarbageValue
    }

    return &data
}