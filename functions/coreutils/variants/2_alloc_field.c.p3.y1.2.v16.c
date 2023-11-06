In Go, the equivalent version of the function can be:
go
func allocField(f int, c *string) {
  ncolumns++;
  columns = append(columns, &fieldData[f])
  if c != nil {
    columns[ncolumns - 1].caption = *c
  }
  if fieldData[f].used == true {
    log.Fatal("Field already used.")
  }
  fieldData[f].used = true
}

Here I’m assuming `columns` is a slice of pointers to `fieldData` structures with a `caption` string field and a `used` bool filed, and `ncolumns` is a global integer variable.
xnrealloc appears to be a custom method used in C to resize memory blocks, in go `append` covers the functionality provided by xnrealloc.
The `affirm` call in C code would be equivalent stopping the execution if the condition is not met, hence the `if fieldData[f].used == true` condition and `log.Fatal` call (I have chosen log.Fatal which exits after giving the errors, the choice depends on how one wants to handle the error.).  If I knew for sure how affirm is implemented I could provide a direct go equivalent. 

This code does assume that out-of-range access and values lager then the length of slice can't happen. If those could happen it would be advisable you add some boundaries checks.