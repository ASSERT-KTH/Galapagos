It seems like your C function is using global variables and is a part of a larger system that is not entirely shown here. Therefore, it's hard to do a direct mapping to Go contextual as Go doesn't support global variable use in the same way due to it's more strict handling of concurrency.

Still, generally this would be a rough representation of the logic provided in Go:

go
var ncolumns int
var columns []*fieldDataT
var fieldData []fieldDataT

type fieldDataT struct {
    used    bool
    caption string
}

func allocField(f int, c string) {
    ncolumns++
    if f < len(fieldData){
        fieldData[f].used = true
        
        if !(f< len(columns)){
            columns = append(columns, &fieldData[f])
        }

        if c != "" {
            columns[ncolumns - 1].caption = c
        }
    }
}


Although various parts of code were improvised upon, e.g., role of the function `xnrealloc` in C code has been taken by `apply` but the core structure remains the same.

To more fully capture the semantic equivalent, we need a more complete understanding of your C source code including types and methods invocations of the `affirm` method and the code that initializes `field_data`.