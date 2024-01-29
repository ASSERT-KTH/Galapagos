In Go, they don't directly support constructors for types like this, unless we had a "constructor function" to achieve the same effect as the example in C.
Please see a similar equivalent code in Go:


type JsonValue struct {
    IsBuilderValue bool
    Type   JsonType
    U      union { 
        Integer int   
    }  
}

func NewJson(t JsonType, i int) *JsonValue {
    return &JsonValue{
        IsBuilderValue: true,
        Type:    t,
        U:      union { 
            Integer: i,
        },
    }
}    
 

Note: Please customize `JsonType` and `union` type as per you system requirements. Here for demonstration purpose, I kept it as basic data type, but these types can be expanded as per the categories present in the JSON data types. This code could be customized as per your requirement because in the limited context of "json_integer_new" function in C that you have shared, it is hard to create an exact equivalent function. 

Additionally, remember that the field `is_builder_value` which was part of the union in the C implementation was added as a separate field inside the `JsonValue` as this is a more common idiom in Go. In Go, union can be represented by interface{}, but sometimes we might lose type safety and need to use `type assertion or type switch` for accessing value. 

Speical Notes: The optional 'Ok' return value from type assertion would be helpful to identify if the asserted type matched with the actual type, and `._type` idiom can be used inside Type Switch in this case.