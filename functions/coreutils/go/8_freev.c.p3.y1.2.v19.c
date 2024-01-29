In Go, garbage with no pointers referencing it is automatically identified and cleaned up by Garbage Collector. In this case, we might have to only to release resources if these represent values that make uses of nullable database/sql types, or apply custom business logic.

However, here is a basic alternative following similar operations:

go
func freeV(v *Value) {
   if v.Type == "string" {
       v.U.S = ””
   } else {
       v.U.I = big.NewInt(0)
   }
   v = nil 
}

In Go, composite types (pointers, arrays, slices, maps, channels) have their zero value being nil so to invalidate them we just have to set them to nil. Remember though that Go will handle memory management for you so most of the time this isn't necessary in your programs for Go unlike in C where you manually deallocate memory using free.