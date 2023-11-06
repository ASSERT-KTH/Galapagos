There are some differences in C and Go that must be accounted for. Go does not support implicit type conversion or pointer arithmetic. We also know nothing about global entities, presumably modified in the background like ncolumns, columns, and field_data. With these things in mind, here is a naive translation:

go
func allocField(f int, c *string) {
  ncolumns++
  
  var temp = make([]field_data_t, ncolumns)
  for i := 0; i < len(columns); i++ {
    temp[i] = columns[i]
  }
  if len(temp) != len(columns) { 
    temp[len(temp)-1] = *fields_data[f]
    columns = temp 
  }

  if c != nil {
    columns[ncolumns - 1].caption = *c
  }
  
  if fields_data[f].used {
    log.Fatal("Field already used.")
  }
  
  // Mark field as used
  fields_data[f].used = true
}


Here we replaced the xnrealloc function with a simple for loop, implemented the affirmations as a fatal log if the condition does not hold (the function will stop working right after it prints the log message), replaced nullptr with nil and renamed the function from alloc_field to allocField.
Also, I've changed the pointers asterisk and ampersand symbols (& and *) because Go treats pointers differently in Go.
Keep in mind if `field_data_t` in C is a typedef to something else, you will need to make sure you account for the relevant mapping in Go's data structures/types. This assumes that columns and field_data are some form of slice on an unknown struct, and ncolumns is an int.