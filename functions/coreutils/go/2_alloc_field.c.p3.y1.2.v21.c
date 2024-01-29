Assuming the "field_data" is a global variable and its type is a slice of pointers to "field_data_t" type structs, and xnrealloc is similar to re-allocation in Golang

go
var (
	ncolumns int
	columns  []*field_data_t
	field_data []*field_data_t
)

func alloc_field(f int, c string) {
	ncolumns++

	// check if we need re allocation
	if ncolumns > len(columns) {
		nc := make([]*field_data_t, ncolumns)
		copy(nc, columns)
		columns = nc
	}

	columns[ncolumns-1] = field_data[f]
	if c != "" {
		columns[ncolumns-1].Caption = c
	}

	if field_data[f].Used {
		panic("assertion failed: field used") // mimic affirm
	}

	// Mark field as used.
	field_data[f].Used = true
}

This doesn't have a absolute 1 - 1 mapping due to differences in language features and syntactical differences. This creates a slice (closest equivalent to array in C) of pointers to field_data_t and handles the reallocation related logic (slice resizing in GO).

Please adjust accordingly based on the whole context of your program.
For equivalence the affirmation logic, Golang doesn't support an exact 'affirm'. So in above code panic() method has been used which will stop further execution similar to affirm.