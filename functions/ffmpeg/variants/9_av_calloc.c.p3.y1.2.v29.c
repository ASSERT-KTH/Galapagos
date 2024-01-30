If we consider the functionality in C, where first memory is allocated and if there is an overflow the C function returns a Null, unfortunately in Go the language specification avoids both overflow and Nans/Null values at compilation expense and design. `make` function only panics when there's not enough memory in the system. Therefore any programmer cannot check if a uint multiplication of sizes is going to lead to overflow. If `uint` doesn't suffice for multiplication it's best the developer breaks the need for such a huge memory into pieces after architecture review instead of aggregating resources through single `make`.

However, settings the direct conversion of calloc and using error that fits GoLang and isn't crossing any language specification below, we can have certain equivalent:

go
func AvCalloc(nmemb, size uint) ([]byte, error) {
	var maxUint = ^uint(0)
	var maxMemSize = maxUint / size

	if nmemb > maxMemSize {
		return nil, fmt.Errorf("uint Overflow")
	}

	totalSize := nmemb * size // total memory bytes size required.
.memory	
	arr := make([]byte, totalSize)
	return arr, nil
}


This is obviously overhead to check if an uint is over-edging through frequent uses of the function which architecture, development and check team supposed to do. Also the real equivalent is just the single line return function if we think syntax difference overly burdensome:

go
func AvCalloc(nmemb, size uint) []byte {
	return make([]byte, nmemb*size)
}
