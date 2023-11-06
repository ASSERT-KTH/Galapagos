In Go, there are no straightforward equivalent operations to the ones the function does in C. Go has garbage collected memory and a much stronger type system. You need to define the types and functions specifically for handling JSON first, such operations also tend to be usually handled by using libraries such as "encoding/json" package in Go. 

A rough equivalence for this function would be:

Go
type jsonValue struct {
    IsBuilderValue    bool
    Type              int
    Integer           int64
}

type jsonInt_t int64

const jsonInteger int = 1 // example constant representing 'json_integer' type

func jsonIntegerNew(integer jsonInt_t) *jsonValue {

    return &jsonValue{
        IsBuilderValue: true,
        Type:           jsonInteger,
        Integer:        int64(integer),
    }
}

This implementation begins by defining types jsonValue (equivalent to the `json_builder_value` struct in C), and jsonInt_t (equivalent to `json_int_t` type in C). The function `jsonIntegerNew()` creates a pointer to a `jsonValue` struct that is returned to the caller.

Please, take this with a grain of salt. Go values correctness, clarity and type safety arguably more than C, and how it works with JSON can entirely be based on its standard libraries. It might well mean, this 1-to-1 translation as you've asked might quite miss the larger point about "how do i approach and simplify things if my project was largely written Go?" If this was your original question, using higher-level constructs can be much more reasonable.

For that purpose, I'd suppose you to define your type to unmarshal/marshal this JSON while changing it as you needed in your project and with the standard libraries which are encoding/json again.