In Go, We can't create a precise equivalent because Go is strongly and statically typed, doesn't have null pointers and memory allocation is garbage collected and not manually managed via calls to calloc/w.e.
But here's a Go function that inherits the spirit of the original:

golang
package main

type JsonType int
const (
    JsonInteger JsonType = iota
)

type JsonBuilderValue struct {
    IsBuilderValue bool
}

type JsonValue struct {
    Type JsonType
    Integer int64
    Value JsonBuilderValue
}

// json_integer_new creates a JsonValue and initializes its type to JsonInteger 
// and its Integer value to the provided integer and returns it.
func json_integer_new(integer int64) *JsonValue {
    value := &JsonValue{}
    value.Value.IsBuilderValue = true
    value.Type = JsonInteger
    value.Integer = integer

    return value
}


The Go function json_integer_new creates and initializes an instance of JsonValue (which would be spelled in common Go Naming conventions as "JsonValue"), sets the accordingly named attributes, and returns the instance (via a pointer).

Like I already mentioned, you won't find calloc/malloc equivalent in strictly dynamically allocated languages like Go. And we don't consider NULL pointer here as if a program is reaching a path where allocating memory fails, your process will likely die soon after, this leaves out the NULL checking part of it.
Please Note: The given C code does a casting to (json_builder_value *) which leads to understandability problems, because the original code is mutating a value into different kinds of values (something like polymorphism). If you find such structure in your code, you might want to bring in usage of Interfaces to achieve the same functionality.