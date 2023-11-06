Go doesn't have direct equivalent for C's `realloc` function, and doesn't allow direct memory manipulation like C does. Therefore, slices (which provides dynamic size) will be ideal to replace C's array in this transition.

The resulting code in Go can be simple:

go
var (
	columns  []*fieldData
	ncolumns int
)

func allocField(f int, c *string) {
	ncolumns++
	newFd := fieldData[f]

	if *c != "" {
		newFd.caption = *c
	}

	if newFd.used {
		panic("Filed is already used")
	}

	// Mark field as used.
	newFd.used = true
	columns = append(columns, &newFd)
}

// Assuming `fieldData` and `columns` array already been defined something similar to below 
type fieldData struct {
	caption string
	p1      byte // place holder for all other data fields, replace `byte` with actual type
	p2      float64  // place holder for all other data fields, replace `float64` with actual type
	used    bool
}

Notes:

- `allocField` function now accepts `c` (caption) argument as string; nil in Go is for pointers, slices, maps, interfaces, chan type variables only. Instead, if you want to provide ability to omit caption when calling this function, you can do so by allowing `c` to be a variadic parameter `c ...string`.
- Go doesn't have built-in `nullptr` (nil pointer), we can use an empty string to equivalent this
- Replaced `xnrealloc` (`realloc`) calls by `append` whice is resize Go slices naturally runtime dynamically
- Error handling done by panic, Go lacks an equivalent mechanism for C's `assert()`. You may substitute this with your log event, or an error return, or a recovery deferral; they best suit Go's error handling propaganda.
- Go allows us to write our program without pointing and dereferencing operations. In Go's program, if any variable stored pointer/bit reference, without specifying dereferencing, iota will automagically dereferenced(provided being used in right expression).