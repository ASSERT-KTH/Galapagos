We've to note that in Go we can't do a direct equivalent of some C concepts such as union and automatic casting due to predefined types. To handle this we can define `JSONValue` as interface, but I can give you a most direct and equivalent version as C code using structs. 

Hereby, "`JSONInt`" was assumed as "`int`". Also, if it is necessary that "`isBuilderValue`" should be private then action could be taken accordingly.

go
type JSONValueType int

const (
	jsonInteger JSONValueType = 1
	// Assume we defined other types.
)

type JSONBuilderValue struct {
	isBuilderValue bool
}

type JSONValue struct {
	jsonFullVal    *JSONBuilderValue
	jsonIntValue   int
	typeOfJSONVal  JSONValueType
}

func NewJSONInteger(integer int) *JSONValue {
	var value = new(JSONValue)

	value.jsonFullVal = &JSONBuilderValue{isBuilderValue: true}

	value.typeOfJSONVal = jsonInteger
	value.jsonIntValue = integer

	return value
}

In this code I've tried to simulate the behavior of the C function you provided in Go. In the initially appeared C version, it looks like "`JSONValue`" has an internal "`union`" part that should be capable of accepting values of different formats. Similarly, the C version has allocation related error handling system (`NULL`), which is handled in Go by the "new" keyword which returns an initialized pointer object, eliminating the NULL check there.