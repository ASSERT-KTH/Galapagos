In the Go code below, please notice few things:

1. Instead of dynamic memory allocation (done in C with 'calloc'), Go directly creates a variable of the type.
2. 'NULL' in C is functionally equivalent to 'nil' in Go.
3. Since Go is a statically typed language, explicit type can't be ignored while value assignment.
4. A value received (integer in this case) can be returned after assigning it to respective type.

Here is the semantically equivalent version the function in Go:

go
type JsonBuilderValue struct {
    isBuilderValue bool
    u              int
}

type JsonValue struct {
    IsBuilderValue bool `json:"is_builder_value"`
    Type           string
    U              *int       `json:"u"`
}

const (
    JsonInteger = "json_integer"
)

func JsonIntegerNew(integer int) *JsonValue {
    value := JsonValue{}
    value.IsBuilderValue = true
    value.Type = JsonInteger
    value.U = &integer
    return &value
}


In this function, an Empty JsonValue{} struct is created with:
1. IsBuilderValue always being set to 'true',
2. Type set as 'JsonInteger'
3. An integer value set in 'U'.

The function then returns a pointer to the struct. If there was an error or 'value' couldn't be created, the function would have returned 'nil'. In this exact implementation, there are no error points or scenarios, where an error might occur.