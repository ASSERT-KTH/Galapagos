In the Go programming language, it's common practice to use the standard library's errors instead of returning null as an error indicator and to make constructs more implicit in the context. However, as you want the syntax to remain unchanged as much as possible, the following is my attempt:

go
type JSONBuilderValue struct {
	IsBuilderValue  bool
	Type            TokenType
	U               *Union
}

type JSONIntVal int

type json_value struct {
	Integer JSONIntVal
}

func json_integer_new(integer JSONIntVal) *json_value {
	var value = new(JSONBuilderValue)
	value.IsBuilderValue = true
	value.Type = json_integer
	value.U = &Union{Integer: integer}
	
	jsonVal := new(json_value)
	jsonVal.Integer = integer

	return jsonVal
}


In this translation, I've attempted to simplify the implementation.

Note: Go does not handle allocations returning possible nulls the way C does, eliminating the need to defensively check whether 'malloc' was successful. If Go were to be unable to allocate memory, it would typically panic rather than return null. The standard 'new' function in Go is equivalent to 'calloc' in C.

However, creating Union and TokenType needs information that isn't given in the original C code. Providing a complete translation would necessitate a more comprehensive understanding of how these values are employed and represented. Hence unless the complete implementation details are provided, the Go replacement can only be approximate.
Since the structure of 'json_builder_value', enum 'json_integer', or the 'json_value' details haven't been supplied in the original C Code, it was necessary to make some assumptions to create an equivalent function in Go.