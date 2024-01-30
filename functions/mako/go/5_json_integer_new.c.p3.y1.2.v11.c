In Go, centralizing data in classes and creating methods to manipulate these data is common practice. However, considering the instructions, it seems that it's desired the function pattern like C language, where there's a set of procedures to manipulate a struct.

In Go we don't have realloc and calloc, we have the built-in make method that has somewhat similar behavior for this kind of creation. People also don't create pointers to pointers, since Go is automatically referenced/dereferenced.

Here is a version of your C method in Go:

go
type JSONValueType int

const (
    JSONInteger JSONValueType = iota
)

type json_builder_value struct {
    is_builder_value bool
}

type jsonValue struct {
    json_builder_value
    valueType  JSONValueType
    integerValue int64
}

func json_integer_new(integer int64) *jsonValue {
    value := &jsonValue{}
    value.is_builder_value = true
    value.valueType = JSONInteger
    value.integerValue = integer
    return value
}


Please, note that I did a series of presumptions, since a lot of context was left out, as we don't know how the original code looks in its entirety.