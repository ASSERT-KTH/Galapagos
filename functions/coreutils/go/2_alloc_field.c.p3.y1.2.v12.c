In Go, we don't have a direct equivalent for realloc function in the C language. But by using the append function effectively we can mimic realloc.

Alternately an "exists" field explicitly marking whether a FieldData wasn't allocated a memory f.e via constructor could also be a solution but here we aimed to maintain the original C implementation to the max extend. Here's the code,

Go
var ncolumns int 
var columns [](*FieldData)
type FieldData struct {
    Caption string
    Used bool
}
var fieldData map[int]*FieldData  

func allocField(f int, c *string) {
    ncolumns++
    columns = append(columns, fieldData[f])
    // check that c is not nil (=nullptr in C)
    if c != nil {
        columns[ncolumns - 1].Caption = *c
    }
    // Affirm that field is not used, in C bool check simply field_data[f].used assuming every item was alloced so only checks value occupancy but in Go also account for nil map membership
    if fieldData[f] != nil && clamp, insideExisting := fieldData[f].Used, field.Get(f); insideExisting && clamp {
      panic("The field is already used!")
    }

    // Mark field as used
    if fieldData[f] == nil {
      fieldData[f] = &FieldData {
          Used: true,
        }
    } else {
      fieldData[f].Used = true
    }
}

This code is considering that fields once marked Used never return to free and hence omitting Allocating memory via resize/initing the map values, may they never existed before. For more idiomatic version handling memory allocation, modulating of defaults and error handling you`d as well better encapsulate who fields definitions as well.