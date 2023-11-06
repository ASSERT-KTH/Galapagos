The equivalent version of the given C function in Go would look like:

go
func allocField(f int, c *string) { 
  ncolumns++
  columns = append(columns, &fieldData[f])
  if c != nil {
    columns[ncolumns - 1].caption = *c
  }

  // Checking if fieldData[f].used is false
  if !fieldData[f].used {
    log.Fatal("Assertion failed: field_data[f].used")
  }

  // Mark field as used
  fieldData[f].used = true
}

Some changes were made because Go doesn't have assertions, so it uses the log.Fatal package as a replacement that achieves similar functionality by logging a message and calling os.Exit(1). An important reminder is that Go works with the garbage collector, so it's not necessary to make a reallocation as in C, and the append function is efficient for these operations. Another detail, the function parameters need to be specified in the Go language.