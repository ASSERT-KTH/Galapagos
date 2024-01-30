Here is a Go equivalent of your C function. 

Please note for this translation, I've considered some assumptions since the C code itself doesn't provide complete context for full conversion. For instance, 'ncolumns' is probably an integer global variable hence, I've supposed a global variable of type int named 'ncolumns'. 'columns' field is probably a pointer to a pointer array of structure field_data_t {}, I replaced this with Go slice included pointer elements, 'field_data' might be an array of structure 'field_data_t', hence I took it an equivalent slice object.

Go
package main 
    
import "fmt"
 
// Struct imitating 'field_data_t' in C
type fieldDataType struct {
used bool
caption *string
}
    
// Mock Data for reference with assumed global vars
var fieldData = make([]fieldDataType, 100)

var ncolumns int
var columns []*fieldDataType
    
func allocField(f int, c *string) {

  ncolumns++

  // Extend the slice
  columns = append(columns, &fieldData[f])

  if c != nil {
     columns[ncolumns - 1].caption = c
  }

  if fieldData[f].used {
     fmt.Println("Assertion Failed - field_data already used")
  }

  // Mark field as used
  fieldData[f].used = true
}


Please note, the input variables don’t need special instructions for being non-null, as Go neither has nullptr nor does it use implicit nullability like C or C++. The 'nullptr'check in C becomes a 'nil' check in Go. Also the '%p' format specifier in C getcharprintf statement equivalent is replaced by '%p' in Go's Printf. Another major change was removal of xnrealloc(), as Go doesn't need explicit de-allocation or resize allocations because of built-in garbage collector hence we use 'append'. It’s also important to know that error handling is different in Go compared to C, Go doesn’t support classical exceptions hence custom logic using fmt with "Assertion Failed" Println used. `'used' is a boolean type, so condition inverted using 'if'.