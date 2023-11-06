import (
   "unsafe"
   "reflect"
)

//go:nocheckptr
//go:linkname MemClr runtime.memclrNoHeapPointers

// Exported function from runtime
// https://godoc.org/runtime#SysUnused
func MemClr(s uintptr, n uintptr)

func SodiumMemZero(pnt unsafe.Pointer, len int) {
     MemClr(uintptr(pnt), uintptr(len))
}