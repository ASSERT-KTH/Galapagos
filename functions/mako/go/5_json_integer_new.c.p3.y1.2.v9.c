In Golang, you cannot set attributes if the method receiver is not a pointer. Because of this, a new function must be created to initialize the structure, in much the same way C mallocs memory and assigns it to a path that is later turned into a structure.

Here's the closest semantically equivalent code  in Go, note that in go there's no need for error catching since the `new` function from the go standard library does the job for us.

go
type JSONBuilderValue struct {
    IsBuilderValue int
}

type JSONValue struct {
    IsBuilderValue int
    Type           string
    Integer        int64
}

func JSONIntegerNew(integer int64) *JSONValue {
    value := new(JSONValue)
    value.IsBuilderValue = 1
    value.Type = "json_integer"
    value.Integer = integer
    return value
}
