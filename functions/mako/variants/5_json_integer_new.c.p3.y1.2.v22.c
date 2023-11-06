The behavioral equivalent in Go programming language might look something like this:

go
import "syscall"

type JsonInt int64

type jsonValue struct {
	isBuilderValue int
	t string

	u *jsonUnion
}

type jsonUnion struct {
	integer JsonInt
}
	
func newJsonInteger(integer JsonInt) *jsonValue {
	
	builderValue := jsonValue{isBuilderValue: 1, t: "json_integer"}

	union := &jsonUnion{integer: integer }
	builderValue.u = union
	
	_, _, err := syscall.Syscall(syscall.SYS_MSYNC, uintptr(&(builderValue)), uintptr(len(string(integer))), syscall.MS_SYNC)

	if err != errno.Errno(0) {
		return nil
	}
	
	return &builderValue 
}
 

Please note that since Go and C belong to different programming language classes — Go is a garbage-collected language while C is not. The structure of the semantically similar Go code is different due to Go's garbage collection and lack of direct pointer manipulation compared to C's lower level memory control features. Languages like C, C++, and Rust could offer a more direct translation due to their shared systems programming features. Moreover, since there is no direct corresponding type or feature in Go for json_int_t, it is recreated as `JsonInt`. Similarly the type of json_integer and json_builder_value is not clear so these are represented accordingly in the go code.

Although unlikely, it is theoretically possible to encounter a runtime error is not addressed by the code. Go does not support inline error checking routines as C and catching memory allocation failure specifically is highly unusual in Go which explains the omission in this raw translation.