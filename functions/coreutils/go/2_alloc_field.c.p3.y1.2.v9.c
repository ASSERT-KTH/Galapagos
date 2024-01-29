Since Go doesn't support the concept of reallocating in an exact manner as C due to automatic memory management, the closest semantic equivalent in Go would be to just append to a slice. 

The main difference between the C`nrealloc` function and the method employed by Go is in the way that memory is managed. In Go, the garbage collector handles the removal of unused memory, whereas in a garbage collector free environment such as C, memory must be manually managed, requiring the `realloc` function when extending/shrinking the memory allocated to a data array.

Assume `fieldData` is represented as a slice of pointers to `FieldData` type. Also, the `FieldData` type is a struct capable of having information as the `field_data` from the C code (an index, and value both caption -string- and used -bool-).

The following code is equivalent:

Go
type FieldData struct {
    used    bool
    caption string
}

var columns []*FieldData
var fieldData [10]*FieldData //or any given size or use a better growable collection (map,slice, etc.)

func allocField(f int, c string) {
    fieldData[f] = new(FieldData)
    columns = append(columns, fieldData[f])
    if c != "" {
        columns[len(columns)-1].caption = c
    }
    if fieldData[f].used {
        panic("Assertion failed")
    }
    fieldData[f].used = true
}


This sample go implementation uses slices. In Go slices are much more efficient and easier to use than dynamically resizing arrays, and provide equivalent functionality. 

Another semantic difference to note; `affirm` is used in C to break the software (and, potentially, debug) in case an assertion is false. Since Go's idiomatic way for handling situations like this consist of errors rather than software breaks, a panic statement replaces the afirm function, which is rough analogue of what is happening on the C code. Please replace accordingly if you need to fit this code elsewhere.