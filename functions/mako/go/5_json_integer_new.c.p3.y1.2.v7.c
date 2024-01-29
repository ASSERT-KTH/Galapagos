GoLang does not allow the same behavior as from C in terms of hybrid data structures containing different data types and doesn't have equivalents for calloc, Therefore direct translation is kind of impossible for such cases. However, trying to give alternative:
Go
import (
    "errors"
)

type JSONType int
const (
    JSONInteger JSONType = iota
)

type JSONValue struct {
    Type JSONType
    IsBuilderValue bool
    Integer int64
}

func JSONIntegerNew(integer int64) (*JSONValue, error) {
    value := &JSONValue{
        IsBuilderValue: true,
        Type: JSONInteger,
        Integer: integer,
    }

    if value == nil {
        return nil, errors.New("Could not create JSONValue")
    } else {
        return value, nil
    }
}

Here, I have declared each field according to given C version of function. Go does not have unions or casting to arbitrary types like C does, therefore trying to create parallel of that with valid datatype fields. Created constant for undefined JSON type values(`jSONUndefined`). So the function sets appropriate JSON types. 
'nil' check is done after assigning memory in 'value' over non-variable & invoked error in case 'value' creation fails similar to way it is checked in "if (!value)" in original code.