In Go, the function would look something like this:

go
import "unsafe"
type FieldDataT struct {
    used    bool
    caption string
}

var ncolumns int
var columns  []**FieldDataT
var fieldData []FieldDataT

func allocField(f int, c *string) {
    ncolumns++
    var gptr *FieldDataT= &fieldData[f]
    columns = append(columns, &gptr)
    if c != nil {
        (*(columns[ncolumns-1])).caption = *c
    }
    if fieldData[f].used {
        panic("field is used already")
    }
    // mark field as used
    fieldData[f].used = true
}



Before running any function, consider the underlying slice we use to hold our data. You can base any additional functionality on this underlying data structure.

Key points in translation understanding are pointers handling and memory management (not necessary in Go). Also, in C, memory must be explictly allocated/deallocated and can be resized, while in Go provides automatic memory management and various built-in types like slices which can be resized automatically using the "append" function.

Also, please also keep in mind, this translation depends on how you would precisely define your types and how your structs are set up in your real scenario, as the C function version doesn't provide complete context.