In Go language, it's not possible to maintain the exact same function as of C code due to certain differences in both the languages such as memory handling, pointer operations, data types and constructor which are available in C but not in Go. However, a possibly akin to inheritance, is defining "methods" associated with types (kind of similar to classes in object-oriented programming), which we employ constructing the different kinds of JSON types.

Below function is an equivalent-ish representation in Go:

go
package main

type JsonBuilderValue struct {
	isBuilderValue bool
}

type JsonValue struct {
	JsonBuilderValue
	Type     string
	Integer  int64
	boolType bool // replacing 'u' (union in C) as we can't have unions in Go.
}

func NewJsonInteger(integer int64) *JsonValue {
	val := &JsonValue{
		JsonBuilderValue: JsonBuilderValue{isBuilderValue: true},
		Type:             "json_integer",
		Integer:          integer,
		boolType:         true,
	}
	return val
}


To give some background, the reasons why the change happened:

In Go, data types are not defined as closely to memory as in C. There is no bigger system of coercion (casting) or cross kind conversion.

Moreover, Go doesn't support ternary operation (?:) the same way with C. It also requires you to explicitly capture unused returned variables.

Instead of throwing a panic, Go implements to return a tuple, where the second parameter is used solely to indicate success or failure. 

Note: C has deeper reach into the memory. It is thus practical within a C codebase to specify json types by bits and bytes, e.g. as structs of varied composition. In Golang rather we simplify to iterable and spannable primitives plus mixing through interfaces and channels and practically only buffered IO.

Lastly, Go prevents pointer manipulation as in C by overspecifying which sorts of data the pointers are bound with. For assignment we become obligated to declare a target memory area `make()` assuredly. For explicit code points where the program could fall into panic. In fact we position handling functions through `defer`.

In terms of structuring the data, we could chose an addressable but empty interface (`map[string]interface{}`) or a verbose telling structure annotated with correct JSON key naming. JSON-to-structure-to-JSON translation becomes straightforward with `json.Marshal()` and `json.Unmarshal()`.
