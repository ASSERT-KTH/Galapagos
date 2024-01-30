Below is the equivalent Go code for the C function given above. It assumes struct `fieldData` and variable `nColumns`, `columns` are located at global scope - just like they are operating on these global variables in your C function. Some data might need to populating where required.

Go
type FieldData struct {
	used   bool
	caption string
}

var fieldData []FieldData
var nColumns uint
var columns []uint

func AllocField(f int, c *string) {
	nColumns++
	columns = append(columns, f)

	if c != nil {
		fieldData[f].caption = *c
	}

	if fieldData[f].used {
		panic("field is already used")
	}

	//Mark field as used.
	fieldData[f].used = true
}


Keep in mind that Go language doesn't have a direct equivalent for 'xnrealloc()' function. This is a GNU extension is used to effectively resize a memory block and null-check the pointer result in a short coded manner, In place of `xnrealloc()` we are simply using `append()` method in Go that increase size of slices(capacity) at run time. 

Please update function code accordingly as required in actual project.