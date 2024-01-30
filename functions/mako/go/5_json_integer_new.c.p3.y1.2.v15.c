In Go, it's most idiomatic to encapsulate functionality into a method of `struct` with associated behaviors. Thus, a struct representing a JSON value and a creation method, `NewIntegerJsonValue`, might look like:

Go
type JsonValue struct {
    isBuilderValue bool
    Type           string
    Integer        int
}

func NewIntegerJsonValue(i int) *JsonValue {
    return &JsonValue{
        isBuilderValue: true,
        Type:           "json_integer",
        Integer:        i,
    }
}


This Go code achieves the same effect as the original C code but does not use `calloc`, since Go does not have uninitialized / null variables unlike in C. Moreover, `json_integer` and `json_builder_value` isn't clear about their type in the provided C code, here I assumed there are constants in `string` type for `json_integer` which we don't use in Go as we are directly assigning the literal "json_integer". We used `int` type for the given `integer` which would map to `json_int_t` mentioned in the C function signature depending upon the integer boundaries considered for solving the problem.