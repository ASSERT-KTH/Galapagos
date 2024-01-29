Given that Go has smarter memory management, there is no need for explicit deallocation of memory like C. Hence `calloc` is unavailable in Go but, we use `new()` or just declare a variable of a type to automatically get a zero-valued assigned memory space.

Also, In Go, variant types (i.e. a value that can have one of several types) are implemented using interfaces.

However, Go does not support generics or union-like types in the manner in C, making it a bit challenging to more perfectly map over the provided C data structures.

Below is an assumption of how the value of the integer, and types are stored in struct using Go.
Due to Go’s strict typing, the method signature not remains with caveat. 

Assuming the interface `Json_Value` and struct `json_builder_value`, and a `json_int_t`:

 go
type json_int_t int
type json_integer int

type Json_Value struct {
	is_builder_value bool
	typ json_integer
	integer json_int_t
}


type json_builder_value struct{
        Json_Value
}

func Json_Integer_New(integer json_int_t) *json_builder_value {
	val := new(json_builder_value)
	val.is_builder_value = true
	val.typ = json_integer(1)
	val.integer = integer

	return val
}
 

Consider these a quite important simplification due to compatible Go hierarchy in types and signature with strict Compilation support when compared to C (dynamic), So makes improper for direct roll over/conversion when stepping from C (Variant and pointer support language) and Go(static and strong typing language). More redesign depending upon project complexity has to be padded when using GO.