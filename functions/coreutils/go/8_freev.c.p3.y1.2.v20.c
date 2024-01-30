In Go, memory management is garbage collected and so, there exists no equivalent of the "free" function. Comparably for the 'mpz_clear' function of GMP library of C, Golang has no existing structures or functions as it doesn't directly interface with GMP.

Here's an abstraction of translating the Go code but noticing the differences outlined:

Go
type ValueType int

const (
	stringVal ValueType = iota
	intVal
)

type value struct {
	valType ValueType
	u       interface{}
}

func freeV(v *value) {
	if v.valType == stringVal {
		v.u = ""
	} else if v.valType == intVal {
		v.u = nil
	}
	v = nil
}


In this Go code the inner value of the 'v' pointer to 'value' struct will have its 'u' field emptied out depending on its ValueType. Then the pointer 'v' itself is pointed to nil.

Note:

1. Go garbage collector will clean up unreferenced/unused data and does not require explicit 'free' calls like C.

2. In C, VALUE has some union which could be a string or mpz_t(a big integer). In Go, there is no direct alternative for a union approach so interface{} is used and further its type is tracked in the 'valType' field. So the precise implementation in Go may alter depending on the TYPE and USAGE.
