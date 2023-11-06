The C function provided uses dynamic array (sadly, not shown in the presented context), reference & dereference of memory pointers, and checks if a certain pointer is not null. 

Unfortunately Go has completely different approach when it comes to manually managing memory - it avoids it as Go has built in garbage collector.

Here is a Go semantically but not structurally equivalent translation for the given C function. It's Assuming, that ncolumns and columns variables belongs to superstructure/context, are defined somewhere before this function.

Go
type fieldData struct {
  caption string
  used    bool
}

type FieldDataHolder struct {
  ncolumns int64
  columns  []fieldData
}

func (fdh *FieldDataHolder) alloc_field(f int, c *string) {
  fdh.ncolumns++
  fd.fcaptions = append(fdh.columns, fdh.columns[f])
  if c != nil {
    fdh.columns[fdh.ncolumns - 1].caption = *c
  }

  if fdh.columns[f].used {
    panic("Field already used!") 
  }

  // The Go convention here is to panic on invariants breach
  // Such as an unexpected impossible turn up here - that is "already used"

  // Mark field as used.
  fd.columns[f].used = true
}

This example assumes that columns `[]*fieldData` (slice of column pointers) have been replaced with columns `[]fieldData` (FieldDataHolder's field, slice of column structures). This is done because in Go you can't have real pointer to structure instance or dealing with uncontrolled memory access.

Please note, that there can't be full migration from C to Go in the same structures using the Garbage collector language approach due to the structural memory organization differences in two functionally different types of language systems. To fit to go - some bigger structural changes would need to be done. Its strongly adviced to a programmer to learn the rationals under decisions responsible for structural changes.