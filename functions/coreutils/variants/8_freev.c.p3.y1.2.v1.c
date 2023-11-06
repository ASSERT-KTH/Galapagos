Creating an exactly semantically equivalent version of the given C++ function in Go is not really possible due to differences in language features and memory management. Specifically, Go has garbage collection, so there isn't a need to manually free up memory like in C++. However, a loose equivalent might look like:

Go
func freev(v *Value) {
	if v.Type == "string" {
		v.U.S=""
	} else {
		_ = v.U.I
		v.U.I.Set(big.NewInt(0))
	}
	v = nil
}
