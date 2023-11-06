Go language does not provide direct mechanisms for manual memory management like C. But this code provided can be converted to match Go's garbage collector environment.


type ValueType int

const (
	StringType ValueType = iota
	IntegerType
)

type Value struct {
    Type ValueType
	StringValue string
	IntegerValue *big.Int
}

func freev(v *Value) {
	v.Type = -1 
	v.StringValue = ""
	v.IntegerValue = nil
}

This solution isolates structure field of Value struct depending on its type, also functions for free memory spaces. They set to default "zero values" to indicate disabled states for the garbage collector. But, always depending on go runtime garbage collection process not manually as C language.`