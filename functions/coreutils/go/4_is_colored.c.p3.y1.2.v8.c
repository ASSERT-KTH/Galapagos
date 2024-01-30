The provided C code uses constructs and methods that don't directly translate into Go: implementation-dependent size_t type, a predefined colorIndicator, and certain string comparison methods. Given Go has garbage-collected runtime, len is just len method, slices and enums are still types differently implemented as compared to C. However, below is the attempted translation considering these points:

go
type IndicatorNo int

const (
	// Define enum values for IndicatorNo here as needed
	IndicatorNoTYPE1 IndicatorNo = iota
	IndicatorNoTYPE2
	// .
	// .
	// .
)

type ColorIndicator struct {
	Len    int
	String string
}

// Assuming an instantiation of colorIndicator mapping similar to what's in the C code
var colorIndicator = map[IndicatorNo]ColorIndicator{
	// Insert corresponding ColorIndicators here 
}

func IsColored(t IndicatorNo) bool {
	ci := colorIndicator[t]
	len := ci.Len
	s := ci.String
	return !(len == 0 || 
            (len == 1 && s == "0") || 
            (len == 2 && s == "00"))
}

Please ensure to match each field of ColorIndicator and enum values of IndicatorNo with your exact requirements. Also, this code supposes the C color_indicator array, in this Go version is put together in a map with IndicatorNo types as the key but if not the case you can modify to fit whatever data structure that enables IndicatorNo to ColorIndicator mapping.