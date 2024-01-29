Go
import "unsafe"

var ncolumns int
var columns []unsafe.Pointer
var field_data []struct {
    used    bool
    caption *string
}

func alloc_field(f int, c *string) {
    ncolumns++

    field_data_t := struct {
        used    bool
        caption *string
    }{
        used: field_data[f].used,
	}

	if c != nil {
		field_data_t.caption = c
	}

    columns = append(columns, unsafe.Pointer(&field_data_t))

    if field_data[f] != nil && !field_data[f].used {
        panic("field already used")
    }

    field_data[f].used = true
}
