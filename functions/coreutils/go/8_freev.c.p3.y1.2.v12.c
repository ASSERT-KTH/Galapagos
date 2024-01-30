There is not a direct semantic equivalent in Go to the provided C code because of Go's garbage collector and the nature of integer large enough to need special cleanup in Go ecosystem.

If `VALUE` is a structure with string and big.Int types, you don't need to explicitly free memory in Go like it's done in C. Once objects are not used anymore, Go's garbage collector will free up the memory.

Nevertheless, if you insist on an equivalent function in Go that correctly checks the type and infer its attribute it will be more or less like this:


import (
  "math/big"
  "fmt"
)

type ValueType int

const (
  ValueTypeString ValueType = iota
  ValueTypeInt
)

type Value struct {
  Type ValueType
  StringValue string
  IntValue *big.Int
}

func FreeValue(v *Value) {
  if v.Type == ValueTypeString {
    v.StringValue = "" // Dispose the string value
  } else if v.Type == ValueTypeInt {
      v.IntValue = new(big.Int) // Reset the integer value
  }
  fmt.Printf("%#v\n", *v) // Testing
}


This sample assumes the StringValue attribute holds the string and IntValue the `*big.Int. You don't really free memory in Go, but here you make them eligible for garbage collection.

Let me know for any additional information.