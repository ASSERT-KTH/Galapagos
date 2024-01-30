Go does not directly support resizing of arrays like C does with the realloc function: arrays in Go have a fixed size. However, this type of resizing behaviour can be achieved using slices. Similarly, Go does not have a concept of a pointer to a composite value like struct as shown here; instead, the address of the composite value can be stored implicitly when the value is assigned to a variable.

The equivalent function in Go can be given as follows:

go
import (
    "errors"
)

type fieldData struct {
    used    bool
    caption string
}

var (
    ncolumns int
    columns  []**fieldData
    column_data [50]*fieldData
)

func  alloc_field(f int, c string) error {
    if f < 0 || f >= len(column_data) {
        return errors.New("index out of range")
    }
  
    ncolumns++ 
    columns = append(columns, &column_data[f])
    if c != "" {
        (*columns[ncolumns - 1]).caption = c 
    }

    if (*column_data[f]).used {
	return errors.New("field already used") 
    } 
   	(*column_data[f]).used = true 
	return nil
}


Here we've recreated alloc_field function is much simpler in Go thanks to built-in dynamism of slices (with append function) and cleaner syntax while checking or assigning struct data. 

Please note in Go exists garbage collector so we cannot have pointer to objects that located on Stack -all those would be lay on heap and would be automatically clean. Important that in struct definition types of parameters -may differ in your code and here this is just example -adjust it to yours needs!