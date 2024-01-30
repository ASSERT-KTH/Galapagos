The following Go code assumes that `columns` and `field_data` were declared and used similar to C's pointer to struct pointers, wrapping them in a struct. However, exact conversion depends upon the fields and setup of your `field_data_t`.

In Go, the variable assignments, structs, and parameter handling works a bit differently:

go
type field_data_t struct {
    used    bool
    caption string
}

type MyProgramData struct {    
    ncolumns int
    columns  []*field_data_t
    field_data []*field_data_t
}

func (d *MyProgramData) alloc_field(f int, c *string) {
    d.ncolumns++
    d.columns = append(d.columns, d.field_data[f])
 
    if c != nil {
        d.columns[d.ncolumns-1].caption = *c
    }

    if d.field_data[f].used {
        panic("Used field is marked!")
    }

    // Mark field as used.
    d.field_data[f].used = true
}    


This Go function follows the semantic equivalences of the given C function:
- It increases the number of columns (`ncolumns++`)
- It reallocates the `columns` slice (`columns = append(columns, newElement)`)
- It then assigns `caption` to `*c` if `c` is not `nil`
- It checks if `field_data[f].used` holds true by negating the condition; panic is a replacement for the C Macro "affirm()"
- Finally, it marks `field_data[f].used` as true.