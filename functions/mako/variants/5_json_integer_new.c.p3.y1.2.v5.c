The Go programming language doesn't support constructors and user-defined type conversion in the same way as C. Though Go doesn't have a perfect 1:1 busbar conversion for this code, as 'type casting' and 'void pointer interpretation' are not available techniques in the language. But here's an adaptation of the spirit of your function, we need to ensure we have a similar structures like in a C program (you can set the structure to whatever you need):

go
package main

type JsonValue struct {
	IsBuilderValue bool
	Type           string
	Integer        int64
}

func JsonIntegerNew(integer int64) *JsonValue {
	value := &JsonValue{IsBuilderValue: true, Type: "json_integer", Integer: integer}
	return value
}

In the above code snippet, we have exactly reproduced the functionality of the C implementation shared by transforming it to its close possible match in Go:

1. Allocates memory and sets default values with initializations, in Go memory is automatically allocated when creating object and default values are set.

2. Sets `IsBuilderValue` to true.

3. Sets `Type` to json_integer.

4. Sets `Intenger` field to the function argument, `integer`. 

5. Returns the 'value' object.