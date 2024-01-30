As Go does not support object programming exactly like C which uses pointers explicitly to handle memory allocations, here is a similar structure written in Go, you may need to choose a suitable replace for is_builder_value field based on your exact design:

Go
type JsonValue struct {
    IsBuilderValue bool
    JsonType       string
    Integer        int64
}

func NewJsonValue(integer int64) *JsonValue {
    return &JsonValue{
        IsBuilderValue: true,
        JsonType:       "json_integer",
        Integer:        integer,
    }
}

In above code, we define a new type `JsonValue` (Analogous to struct json_builder_value). NewJsonValue function plays similar role to json_integer_new.

This dummy function creates and initializes a JsonValue and directly returns a pointer to it like in C. The catch is unlike C, there's no way to fail a memory allocation in Go - when system memory is exhausted, Go will fail with a panic.

Please note, Go has native support for json management in *encoding/json* package, Consider to use that to handle json processing if possible. 
For the same high-level objective, the common practice in Go world is using Marshal/Unmarshal Interface from package *encoding/json* instead of handling it in C-like way. (like casting type often) ; That could be the 'Go' way of doing it.