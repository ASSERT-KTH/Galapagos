In Go, conversion to reference function semantics from C to Go might involve leveraging structs and interfaces because Go is not a prototypal language. Here is an equivalent function in Go:

go
type JsonValue struct {
    Type  string
    U     JsonU
    IsBuilderValue bool
}

type JsonU struct {
    Integer int64
}

func JsonIntegerNew(integer int64) (*JsonValue, error) {
    value := &JsonValue{
        Type:          "json_integer",
        U:             JsonU{Integer: integer},
        IsBuilderValue: true,
    }

    if value == nil {
        return nil, errors.New("Could not create JSON value")
    }

    return value, nil
}


Here we leveraging Go's creating struct and error reporting mechanisms for equivalent behavior. JSON values are represented as Go structs.