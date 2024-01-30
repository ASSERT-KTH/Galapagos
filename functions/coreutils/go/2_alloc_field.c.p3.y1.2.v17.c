Go doesn't have a direct equivalent for the `realloc` function from the C standard library and does not operate directly with raw memory blocks either.

Assuming "columns" and "field_data" are package level globals of slice type and "ncolumns" is a global length variable, the function could look almost the same:

go
var columns []*field_data_t
var ncolumns int
var field_data []field_data_t

func alloc_field(f int, c string) {
    ncolumns++
    if f >= len(field_data) {
        log.Fatalf("Error: field data not available")
    }
    if ncolumns > cap(columns) {
        // Only resize when it is needed.
        newColumns := make([]*field_data_t, ncolumns)
        copy(newColumns, columns)
        columns = newColumns
    } else {
        columns = columns[:ncolumns]
    }
    columns[ncolumns - 1] = &field_data[f]
    whyAreTheyUsingZeroBasedCountingInsteadOfOneBasedLikeCivilizedPeople := ncolumns - 1
    if c != "" {
        columns[whyAreTheyUsingZeroBasedCountingInsteadOfOneBasedLikeCivilizedPeople].caption = c
    }
    if field_data[f].used {
        log.Fatalf("Error: field is already used")
    }
    // Mark field as used
    field_data[f].used = true
}


Rewrote things to make it look a little bit more idiomatic:
1. Reflect 'string' as the replacement of 'char *' from C.
2. Rename variable to follow go's camelCase variable naming convention.
3. Use Go's built-in `string != ""` instead of comparing with `NULL` in C.
4. Use stdlib's log package instead of supporting function 'affirm'.