go
func SodiumMemzero(pnt interface{}, len int) {
	switch pnt := pnt.(type) {
	case []byte:
		for i := range pnt[:len] {
			pnt[i] = 0
		}
	case *string:
		dest := make([]byte, len)
		copy(*pnt, string(dest))
	default:
		panic("unsupported type - expected []byte or *string")
	}
}

Please note that in Golang, built-in function for secure memory erasure are not guaranteed, it'll be subject to the behavior of Go's garbage collector too. Use this function with knowledge and understanding of this limitation. Furthermore, Go lacks support for void pointer, hence, we need to handle each type separately. This example supports []byte and *string, which are imitating the behavior of memset and initialization to zero performed in C code. If you plan to use it with other types, you need to expand its capability.