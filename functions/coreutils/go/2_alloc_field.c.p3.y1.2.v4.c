This code should equip in one class to implement in golang.
Golang
package main

import (
	"unsafe"
)

type FieldData struct {
	used    bool
	caption string
}

var NColumns int
var Columns []*FieldData
var FieldData [100]FieldData // as it is just an snippet, used this to depict samantic equivalent


func AllocField(f int, c string) {
	NColumns++
	tempColumns := make([]*FieldData, NColumns)
	copy(tempColumns,Columns)
	Columns = tempColumns
	Columns[NColumns - 1] = &FieldData[f]
	if c != "" {
		Columns[NColumns - 1].caption = c
	}
	if FieldData[f].used {
		// assert
		panic("cannot use a used field")
	}
	// Mark field as used.
	FieldData[f].used = true
}
