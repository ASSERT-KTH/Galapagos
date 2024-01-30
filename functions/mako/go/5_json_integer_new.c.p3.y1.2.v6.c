Due to differences between C and Go, it's not possible to replicate the function exactly as in C. Go doesn't have constructors like C and also it does not support union types directly like C `json_u`. However, the following implementation attempts to replicate as much functionality from the json_integer_new C function as possible:

It's important to note that in Go:

- The idiomatic way to handle errors is to use multiple return values, not null values.
- As you move values between functions, Go automatically handles and cleans up memory.
- Instead of using malloc/calloc and free yourself, you oftentimes work with values directly and let Go's garbage collector clean up.

Here is the equivalent Go code:

go
package main

type JSONInteger struct {
    Type      string
    isBuilderValue int
    Integer   int64
}

func NewJSONInteger(integer int64) (*JSONInteger, error) {
    value := &JSONInteger{
        Type:     "json_integer",
        isBuilderValue: 1,        
        Integer:  integer,
    }
    
    if value == nil {
        return nil, fmt.Errorf("Failed to create new JSONInteger instance")
    }

    return value, nil
}


The Go function creates a new struct of type `JSONInteger`, which contains fields Type (equivalent to `type` in C) and Integer (equivalent to `u.integer` in C). struct type so it doesn’t need explicit initialization of memory like C. Initialization and deinitialization (clearing) memory are handled by Go's garbage collector. So it simplifies the code by leaving out `calloc`.

Go does not support union datatype so it is not possible to convert that exactly. structs are almost always used for grouping and managing multi fields.

The JSONInteger struct also helps achieve more reliable go-to-json serialization when converting the struct type into a json string using json.Marshal and json.Unmarshal. The go struct will automatically get correct json tags when serializing and deserializing according to Go's struct field name.