It's not possible to transform the provided C code into exactly semantically equivalent Go code directly due to a number of reasons. Firstly, In Go language, there is no direct equivalent for C's `free()` function. This is because Go has Garbage Collector that automatically manages memory. Secondly, Go does not support unions like C does. Therefore, there'll be a structure-based workaround to keep `string` or `mpz` value in use. Lastly, `mpz_clear` relates to GMP (a library for arbitrary precision arithmetic in C), so Go equivalent based around similar library (say, math/big) can't have `Clear()` in a solution. So, there are necessary modifications to mirror function's usage in Go:

go
import (
	"math/big"
)

type ValueType int

const (
	StringType = iota
	IntType
)

type BigIntPtr struct {
	Ptr *big.Int
}

type Value struct {
	Type      ValueType
	StringVal string
	IntVal    BigIntPtr
}

func freev(v *Value) {
	switch v.Type {
	case StringType:
		v.StringVal = ""	// setting an empty string promotes garbage collection
	case IntType:
		v.IntVal.Ptr = nil	// setting a nil value promotes garbage collection
	default:
		// handle other types or default
	}
}

When you wish that memory being referenced by local value becomes eligible for garbage collection, you just need to allow Go to understand you don't need it anymore. This is achieved by assigning appropriate zero values.