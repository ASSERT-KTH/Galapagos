Go tries to avoid explicit memory management and manual "freeing" as seen in C, and instead relies on automatic garbage collection by the presented runtime. Therefore, typically you wouldn't have free or similar functions in Go.



But let's assume that there might be a need to manually "clean up" an object of type VALUE. We need an equivalent function:



Go

// assuming that we have the following types mapping C types:
type ValueType int
var StringType ValueType = 1

type Value struct {
    t ValueType
    u interface{}
}

func SetValue(v *Value) {
    switch val := v.u.(type) {
      case string:
          // If the u field contains a string value, we set the string to empty string
           v.u = ""       
       case *big.Int:
           // If the u field contains a big.Int, we set the integer to 0
           v.u = new(big.Int)
          // clean up...
   }
}

But remember, in Go you normally won't have to do such explicit clean up. The garbage collector will remove objects from memory that aren't being utilized. This may cause an object to lose its value before you have explicitly released it (although the GC is pretty good at telling when something is still being used). It's important to note that usually in Go, reducing reference pointers assists in releasing memory backto the garbage collector.
A side note: mbedtls (a cryptographic gignature software) and cgo notes explicit usage of free function using c commands in the files which is really controvertial when mixing garbage collected systems with manually managed code thus criticized by some of the developers. 