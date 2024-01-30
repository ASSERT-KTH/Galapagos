func allocField(f int, c *string) {
    ncolumns++
	columns = append(columns, &fieldData[f])
	if c != nil {
		columns[ncolumns - 1].caption = *c
	}

    if fieldData[f].used {
        panic("Field already used")
    }

	fieldData[f].used = true
}