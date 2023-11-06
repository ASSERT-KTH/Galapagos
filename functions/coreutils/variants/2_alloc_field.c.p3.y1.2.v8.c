The Go programming language does not directly support the realloc operation, necessary for dynamic resizing of slices or arrays. Instead, Go accomplishes resize tasks using built-in copy() and append() functionality. Furthermore, in Go "NULL" has to be replaced by "nil", and Go has non-nullable types and true boolean values. Here's the the equivalent functionality of your code in Go:

go

var Columns []*FieldDataT
var NColumns int
var FieldData []FieldDataT

type FieldDataT struct {
	caption string
	used    bool
}

func AllocField(f int, c string) {
	NColumns++
	if f >= len(FieldData) {
		temp := make([]FieldDataT, f+1)
		copy(temp, FieldData)
		FieldData = temp
	}
	cells := FieldData[f]
	if c != "" {
		cells.caption = c
	}
	if cells.used {
		panic("Field is already used")
	}
	cells.used = true
	if NColumns > len(Columns) {
		temp := make([]*FieldDataT, NColumns)
		copy(temp, Columns)
		Columns = temp
	}
	Columns[NColumns-1] = &cells
}


Please note:
- The error signaling method that could be chosen, for when the assert condition fails, depends on further context. I have chosen to raise a panic because the original code uses "affirm", which appears to be something passed for signalling, which would be similar in function to a panic; you can conclude with the idea using other error methods according to your comfort and requirement.
- Original C++ code snippet assumes `columns`, `ncolumns` and `field_data` to be the global variable in the module scope - In Golang rewrite, a same level of usage is retained.
- Array initialization with non-zero values is moved inside the function (like ncolumns++ line), as Go do not support variable declaration and initialization with non-zero values outside of function scope.
- Here`field_data_t` is considered as Go struct. Boolean (true or false), string (const char*) are the equivalent types in Golang.