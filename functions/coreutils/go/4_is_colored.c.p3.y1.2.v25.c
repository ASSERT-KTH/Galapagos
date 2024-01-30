In order to create an equivalent function in Go, we need to somewhat adjust things a bit taking go programming into consideration. 

Please adjust "colorIndicator", "Indicator_No", the data types for "len" and "string" inside "color_indicator" to fit your actual data types. It is a rough translation as there is significant translation issue due to C and Go language differences, and lack of context.

Here is how it would look like in Golang,

Go
package main

type ColorIndicator struct {
	Len    int
	String string
}

type IndicatorType int

func isColored(colorIndicator []ColorIndicator, type IndicatorType) bool {
	c := colorIndicator[type]
	len := c.Len
	s := c.String
	
	if len == 0 || (len == 1 && s == "0") || (len == 2 && s == "00") {
		return false
	} else {
		return true
	}
}

Please note that in Go, it is recommended to use standard naming conventions starts with a lowercase letter for both global and local variables while names of structs, methods usually start with uppercase.
Also, please replace "ColorIndicator  []colorIndicator" etc with your own data types that hold equivalent value and functionality based on the context from your implementation. 
Different to C, Go uses Slice instead to dynamic array operations, hence used that for conversion of color_indicator above. Same needs to be adjusted as per your array requirement.
Indicator_No and enum equivalent used here is to replicate enum from original. Please adjust as per your usage.