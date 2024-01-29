In Go language, we handle memory deallocation in a different way due to its built-in garbage collector mechanic. Here's a comparable way, it sets the values to nil and let them be cleaned out when no pointers utilising the data are accessible.

go
func avFreep(arg *interface{}) {
	*arg = nil
}


Note: `av_free()` in C is not transforming to Go as manual memory deallocation is unnecessary due to garbage collection by Go. Control the lifetime of an object in Go by managing the scope of ID's and through Structs. The Go garbage collector will kill an item's allocated memory when all references / ids to it are out of scope.