In Go, the equivalent function implementation of `alloc_field` would be as follows:

go
func allocField(f int, c string) {
    nColumns++
    var fieldData []*struct {Caption string; Used bool}

    columns := make([]*struct {Caption string; Used bool}, nColumns)
    copy(columns, fieldData)
    columns[nColumns - 1] = &fieldData[f]
    if c != "" {
        columns[nColumns - 1].Caption = c
    }

    if fieldData[f].Used {
        panic ("field is not valid")
    }

    // Mark field as used. 
    fieldData[f].Used = true
}

The C structure `struct field_data_t` with fields `caption` and `used` were mappedto struct  type with fields `Caption` and `Used`, accordingly.

Please, make sure, the variables `columns`, `ncolumns` and `fieldData` is declared into a correct scope.