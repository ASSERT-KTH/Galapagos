As Golang uses different approach in error handling, it may requires the presence of error handling. 

Go also does not support classes and inheritance as seen in C++, but it exploits its interface, struct, and package well to build modular and reusable types and components. Hence a fairly equivalent implementation of the function in Go would be:

go
type JSONBuilderValue struct {
	IntVal int64
}

func JsonIntegerNew(integer int64) (*JSONBuilderValue, error) {
	value := &JSONBuilderValue{IntVal: integer}

	if value == nil {
		return nil, errors.New("Failed to create new JSON integer")
	}
	return value, nil
}


The provided Go code creates a new JSON builder value by initializing a significant integer to a desired variable by modifying its value method and returns a pointer to the JSON integer “value object” and nil as error. If it fails to create the value object, it returns a nil pointer and provides a detailed error message. Furthermore, this equivalent Go code does not utilize `is_builder_value` property of json_builder_value structure because type tracking in Go is handled by the compiler for type safety unlike C.