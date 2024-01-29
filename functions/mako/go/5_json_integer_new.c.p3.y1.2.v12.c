Go language does not support functions like calloc and casting such as in the C language. This is due to Go containing automatic memory management or garbage collection. Also, Go's type structure differs significantly from that of C.

However equivalent functionality could be achieved in Go.

go
type JSONValue struct {
    IsBuilderValue bool
    Type           string
    Value          jsonInt    
}

type jsonInt int64

func NewJSONInt(i jsonInt) *JSONValue {
    return &JSONValue {
        IsBuilderValue: true,
        Type: "json_integer",
        Value: i,
    }
}


Here it's important to know that we should use NewJSONInt(...) instead of json_integer_new(...) in Go. Go doesn't have constructor or class methods as there are in C or other languages. The "New" functions (json_integer_new in C in your case) act as the constructors in Go. The idiomatic way to do so in Go is to use the prefix "New" followed by the Type. 

So based on golang conventions the above code snippet should ideally look like this:

go
type JSONInt jsonInt

//etc. 

func NewJSONInt(i JSONInt) *JSONValue {
//etc.


Here JSONInt will be considered as a separate data type entirely equal to jsonInt yet different, coming handy when various libraries have same data types and we wish to avoid name collision. Also, as per Go conventions, public methods, functions and Data types have the first letter in CAPS.