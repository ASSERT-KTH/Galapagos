In the Go programming language, it would be appropriate to use a strategy of structs to model your data, along with methods acting on these.

Please naote, Go does not hoave the concept of constructors like in C or C++, nor does it uses "new" keyword (that used only for inatializing memory for variables). Instead, if we want to mimic, Initialise function should be created that is used as constructor to initialise any required variables or data to the required type of structure.

Below is the C function parsed to Go as much as practically feasable with maintained structure 

go
type JsonBuilderValue struct {
    IsBuilderValue bool
}

type JsonValue struct {
    JsonBuilderValue
    Type string
    U    int64
}

func JsonIntegerNew(integer int64) *JsonValue {
    value := &JsonValue{
    Type: "json_integer", //you may change "json_integer" to the actual variable in your environment
    JsonBuilderValue: JsonBuilderValue{
        IsBuilderValue: true,
    },
    U:     integer,
   }
    return value
}

We could use `json` struct tags on the struct fields to define how the struct is serialised to JSON and how it can be deserialised from JSON back to our struct type. However, that changes the structure such creaeated maintainig the layout and structure of oiginal C function.