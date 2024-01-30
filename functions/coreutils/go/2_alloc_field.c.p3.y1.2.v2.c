The translation of this function into Go language demands an explicit consideration of some things. First, there isn't direct equivalent of realloc in Go as proper memory management is handled for you already. We rather make use of the slice capability in Go.

Since the struct field_data usage dosn't seem quite clear because of undefined variables or types in the C function, we need such definition to make exact translation.

Let's imagine that we have defined the struct in Go like so:


type FieldData struct {
	Used    bool
	Caption string
}


And we are storing these in a basic slice `columns` which we will grow as needed:

`var columns []*FieldData`

We can write an approximate Go equivalent to this C function sumnaming the following variant is present as this function relies heavily on global variables -

// We need to declare ncolumns as global variable.
var ncolumns int
var field_data = make([]FieldData, 10)

And than the function -

go
func allocField(f int, c *string) { 
	ncolumns++ 

	// Equivalent to xnrealloc in Go, resizing the slice
	columns = append(columns, &field_data[f]) 

	if c != nil { 
		columns[ncolumns - 1].Caption = *c 
	} 

	// Consider the next block line is the equivalent of affirm in Go
	if field_data[f].Used == true { 
		log.Fatal("Field already in use.") 
	} 

	// Mark the field as in use
	field_data[f].Used = true 
} 


Please note, the solution is provided based on an indicative perspective as some of the variables are undeclared and unspecified in provided c code. Their indicaive meanings are considered for implementing the go function.