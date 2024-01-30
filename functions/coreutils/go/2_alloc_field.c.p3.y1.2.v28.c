go
//due to golang's statically typed nature, proper available details are important.
//Assuming ncolumns, columns and field_data have been appropriately defined:

func allocField(f int, c *string) {
    ncolumns++
    columns = append(columns, &field_data[f])
    if c != nil {
        columns[ncolumns-1].caption = c
    }
    if field_data[f].used {
        panic("Field already in use.") // As "Assert" function is handle manually in Go
    }

    // Mark field as used
    field_data[f].used = true
}                  
