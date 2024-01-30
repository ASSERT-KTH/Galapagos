In Go, as it is a safe and statically typed language, some concepts don’t directly translate from C. The Go memory management model doesn't explicitly allow to allocate size (`calloc`). Also, explicit typecasts are done only with compatible types in Go, unlike C where it possible to typecast any pointer type to other pointer types.

Also type modification like `json_integer_new` would ideally implemented as methods not as a isolated function.

Anyway, an approximate translation of your C function to a Go format is as follows:

go
import "encoding/json"

type JsonValue struct {
    IsBuilderValue bool
    Type json.Number
    Integer int64
}

func NewJsonInteger(integer int64) *JsonValue {

    value := &JsonValue{
        IsBuilderValue: true,
        Type: json.Number(strconv.FormatInt(integer, 10)),
        Integer: integer,
    }
    
    return value
}

Please note the major differences between the original code and the one in Go:

1. In Go, there is no requirement for explicit nil check after allocation, as Go's zero value semantic ensures that everything is automatically initialized.

2. There is no concept of typecasting that's done in the C code, as without having the `json_builder_value` struct definition in Go, we can't reproduce that part.

3. Memory & Error handling aren't the same between Go & C. The language constructs are very different compared in the two.

4. If you are using "encoding/json" package in Go, you should use `json.Number` for json number handling not any custom defined types. 

5. This is a pseudo-conversion. The Go programming paradigm is fundamentally different in many aspects from C. Adopting C coding practices directly to Go sometimes result in ineffective and cumbersome Go code.