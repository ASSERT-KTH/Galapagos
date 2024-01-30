Given that Go does not have a direct equivalent of C-like pointers (or pointer arithmetic in array), and does not support nullptr check (since it favors zero value of data types instead), the function below implements as much of the original functionality as possible. However, it must use slices instead of a raw array (columns[]) and it is for type FieldData, since Go does not have the concept of "void pointers" or unlimited kinds of data in an array. 

To stay as close as possible by having both caption variable with string data type and used variable with boolean data type in the function, a structure is also used named FieldData. It is not set to required *FieldData struct since in C version, it does not initiate FieldData.

type FieldData struct {
	Caption string
	Used    bool
}

var ncolumns int
var columns []FieldData
var fieldData [99]FieldData

func allocField(f int, c string) {
	ncolumns++
	// We copied the slice to maintain similarity to realloc
	temp := make([]FieldData, len(columns))
	copy(temp, columns)
	columns = temp

	columns[ncolumns-1] = fieldData[f]
	if c != "" {
		columns[ncolumns-1].Caption = c
	}

	if fieldData[f].Used==true {
		panic("Field has been used before this operation.")
	}

	// Mark field as used.
	fieldData[f].Used = true
}