Go does not support constructor-like behavior or direct type casting like C, but provides an alternate way we can increase memory and work with interface types. Below is our best transformation of the C code into Go:

go
type json_value struct {
     is_builder_value bool
     Type             string
     integer          int64
}

func json_integer_new(integer int64) *json_value {

    value := &json_value{}

    value.is_builder_value = true
    value.Type = "json_integer"
    value.integer = integer

    return value
}

In the Go version of the code, Go's memory management automatically provides you 'zero' memory semantics automatically, making explicit memory allocations unnecessary. Also, instead of using bit fields as done with C, Go uses more straightforward bool type. Reason being that, for a boolean, it does not really save meaningful amounts of space, and performance implications would generally be negligible.
The integer value is as well set effortlessly by just assigning it to "integer." In the end the function finally returns the object's pointer, keeping object allocation and initialization separated as in the original C version. 
Note: Go uses different data types. It's suggested that json_int_t is roughly equivalent to int64 in Go. Kindly double-check to verify the types, transformation may vary if the int data type is not same. 

Lastly you asked for keeping original function signature same, please note this can't be totally adopted as Go programming language doesn't support behaviour like constructor to keep the function signature totally alike.