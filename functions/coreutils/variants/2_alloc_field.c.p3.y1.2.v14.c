Go does not support pointers to two-dimensional array structures in the same way, so a direct translation may require a significantly altered code design. Nonetheless, my attempt to preserve as much of the original logic in Go while maintaining the function's original signature would be looks like the following.

Golang does not have nullptr or null. Golang has default value for every type.  For string, it is "".

Designed function considering feild_data array as global with a structure defined globally and then accessed inside the function.

go
import "fmt"

// Assuming we have previously defined field_data structure and slice columns globally
type field_data_t struct {
    used    bool
    caption string
}
var field_data []field_data_t
var columns []field_data_t

func alloc_field(f int, c string) {
    columns = append(columns, field_data[f])
    nColumns := len(columns)
    if c != "" {
        columns[nColumns-1].caption = c
    }
    if !field_data[f].used {
	    panic(fmt.Sprintln("field_data[%d] should not be used", f))
    }
    field_data[f].used = true
}
 

The `affirm` function is not provided in this implementation since it feels out of place and would hinder direct translatabity-Error during compilation if included. If needed can be replaced with Go error handling or panic . And not following exact panic situations from original code because usually in Go it is not recommended to use panic instead if still we need to replace ,it should be use in IDK, NI situations.