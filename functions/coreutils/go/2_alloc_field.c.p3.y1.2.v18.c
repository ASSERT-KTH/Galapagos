In Go, we can no longer directly resize slices as in C. Instead, the built-in append function handles dynamic resizing of slices. In addition, it doesn't have a direct equivalent for C's static arrays so assign column `f` of `fieldData` a new slice value instead. Here's how the given code would look if we were to translate it verbatim to Go:

go
type FieldData struct {
    Used    bool
    Caption string
}

var nColumns int
var columns []FieldData
var fieldData []FieldData // equivalent of field_data structure in c 

func allocField(f int, c string){
    nColumns++
    if len(columns) < nColumns {
        columns = append(columns, fieldData[f])
    } else {
        columns[nColumns - 1] = fieldData[f]
    }

    if c != "" {
        columns[nColumns - 1].Caption = c
    }

    if fieldData[f].Used {
        panic("field already used")
    }

    // Mark field as used.
    fieldData[f].Used = true
}


Please adopt the usage of golint for the Go coding formatting and high readability. 

Go does not have inherent assertion functionality like ‘C’. So we made use of panic(), but if you anticipate errors more frequently, better error handling is advised which resusts consequent operations in case of failure properly. Make sure you handle this by recovering from the panic, in condition panic gets triggered. 

For safety, please confirm `f` does not go beyond the bounds of `fieldData`. Let's consider implementing error handling to keep your program robust.

Dependencies for `FieldData` should be defined else where in separate dependent package or inside the same package.