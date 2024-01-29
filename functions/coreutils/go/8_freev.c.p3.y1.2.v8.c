It's worth noting that Go, by nature, differs significantly from C, particularly with its garbage collection and lack of direct memory manipulation functions like malloc() and free(). Thus, an exact conversion can't be performed. However, here is an equivalent function that adheres to Go's memory management methodologies:

go
type ValueType int

const (
    String ValueType = iota
    Int
)

type VALUE struct {
    DataType ValueType
    StrData  string
    IntData  *big.Int
}
    
func freev(v *VALUE) {
    
    if v.DataType == String {
        v.StrData = ""
    } else if v.DataType == Int {
        v.IntData = new(big.Int)
    }
    
    // In Go, setting to nil makes v eligible for garbage collection
    v = nil
}


Note: In Go setting a variable to "nil"(zero-value for pointers, interfaces..., including pointer to strings like in your code) does not automatically free the memory like it would in C, rather, It makes the data structure eligible for garbage collection, At an undetermined point in the future, the garbage collector will free the memory if it determines no other parts of the program can access this data.