Unfortunately, translating this exact function to Go is difficult because these kinds of direct reallocations or dynamic memory management are not possible in Go as it handles memory allocation automatically/garbage collected.

However, author's intent can be completed provided with equivalent Go code with Go's implementation:

Go
type FieldData struct {
	used bool
	caption string
}

var Columns []FieldData
var NColumns int

func AllocField(f int, c *string) {
	NColumns++
	newColumns := make([]FieldData, len(Columns))
	copy(newColumns, Columns) // xnrealloc equivalent - get new set of columns and copy old into it
	Columns = append(newColumns, &FieldDataRefs[f])

	if c != nil {
		Columns[NColumns - 1].caption = *c
	}
	
	if FieldDataRefs[f].used {
		panic("field is already used") // equivalent to affirm
	} 

	// Mark field as used
	FieldDataRefs[f].used = true
}


Please note however, that like the original C example, these Go code also makes a lot of assumptions beyond the scope of the function (like with already existing nColumns integer, Previous `FieldData` type and list...) because to equivalent conversion, I needed to assume those requirements. Please revise them accordingly for your actual needs.