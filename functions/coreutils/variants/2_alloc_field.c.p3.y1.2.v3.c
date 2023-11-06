In Go, due to its strong typing, we can't just cast a variable of type T into type *T. Therefore, to implement the equivalent functionality of this C function, we would need to change `field_data[]` to type `[]*fieldData`.

go
type fieldData struct {
    caption string
    used    bool
}

var ncolumns int
var columns []*fieldData

func alloc_field(f int, c *string) {
    ncolumns++
    field_data := make([]*fieldData, len(columns)+1)
    copy(field_data, columns)
    columns = field_data
    column := &fieldData{
        caption: "",
        used:    false,
    }
    field_data[f] = column // let's assume that f lies within bounds of field_data
    columns[ncolumns-1] = field_data[f]
    if c != nil {
        columns[ncolumns-1].caption = *c
    }

    if field_data[f].used {
        panic("Field data is already in use")    
    }

    field_data[f].used = true
}
