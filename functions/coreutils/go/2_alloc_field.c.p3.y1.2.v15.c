Because Go doesn't have a resizeable array type like C does (slices aren't the same as they are backed by an array of a specific size which cannot change), without major redesigning of the code, we can't straightforward convert it into Go. Moreover, the handling of null pointers in Go is a bit tricky as they are not supposed to be used the same way as in other languages (as non-initialized variables). The third issue is in handling the "used" property which we won't be able to do without changing the struct's properties which is out of the scope currently.

But assuming that such conversions are possible by tweaking field_data from an array into a map, here is a sample translation:

go
import "sync"

type FieldData struct {
  caption string
  used  sync.Map
}

var (
  nColumns int
  columns = make([]*FieldData, 0)
  fieldData = make(map[int]*FieldData)
)

func allocField(f int, c string) {
  nColumns++
  fieldData[f] = &FieldData{}
  columns = append(columns, fieldData[f])
  
  if c != "" {
    columns[nColumns - 1].caption = c
  }
  
  _, ok := fieldData[f].used.Load(f)

  if ok {
    panic("field already used");
  }

  fieldData[f].used.Store(f, true)
}


The code achieves similar goals in principle with synchronised maps instead of using resizeable arrays. It assumes that the Go version of `field_data_t` is an map of pointers to `FieldData`. Each `FieldData` holds caption, used state stored as key-int, value-bool. In Go, adjustment of arrays and equivalent unsafe pointer arithmetics to manage memory as done in C is not required (and recommended).

Please note: In Go zero value (equivalent to nullptr in C) for string is "", i.e. empty string, therefore we check if string paramater, c, is empty or not rather than checking for `nullptr`. Similarly for bool, zero value is `false`, and it does not need an explicit assignment inside `FieldData`.