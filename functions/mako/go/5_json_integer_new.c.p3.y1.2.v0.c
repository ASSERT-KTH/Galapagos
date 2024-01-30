It's important to note that Go doesn't have direct equivalent language constructs or types to all in C. However, I'll give you code that is according to the principle and it requires that `Value` and `Type` are defined in Go. And I account for very basic JSON representation: 

go
type Value struct {
    Type     string
    Integer  int
    IsBuilderValue bool
}

func NewValue(integer int) *Value {
    return &Value {
        Type:   "json_integer",
        Integer:  integer,
        IsBuilderValue: true,
    }
}


Remember, we cannot do the process of "casting" and direct memory mapping as performed in C, because these features do not exist in Go in the same way. This means we need to create the concrete types ahead of time and new instances of this type fill the fields explicitly. Also, Go does not support ternary (`value ? something : else`) statements.