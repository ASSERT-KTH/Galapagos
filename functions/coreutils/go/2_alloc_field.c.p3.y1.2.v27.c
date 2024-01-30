It's not possible to safely "translate" a C version of a function into Go due to many aspects of the languages being structurally differently (differently managed garbage collection, pointer handling...). Hence, maintaining an exact signature is complicateis.

Also, the data structures the C function operates – `field_data`, `ncolumns`, etc. aren't described anywhere, that makes the exact conversion is difficult in absence of context of types and memory allocation (e.g., `xnrealloc`). Anyway, a possible reference implementation that you could change according to your specific situation should lie this:

go
var nColumns int
var fieldData []fieldDataType
var columns []*fieldDataType

type fieldDataType struct {
	used    bool
	caption string
}

func allocField(f int, c *string) {

	tmpCap := c
	if c == nil {
		defaultCap := ""
		tmpCap = &defaultCap
	}

	fieldData[f].used = true
	fieldData[f].caption = *tmpCap

	nColumns++
	if f < len(columns) {
		columns[f] = &fieldData[f]
	} else {
		columns = append(columns, &fieldData[f])
	}

	if fieldData[f].used {
		panic("Field f was used already")
	}
}

