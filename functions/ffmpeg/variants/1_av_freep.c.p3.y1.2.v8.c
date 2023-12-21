In Go, this style of function is generally not needed because Go escapes manual memory management using garbage collector. However, here is an equivalent function with closer semantics:

go
import "unsafe"

func AvFreep(arg unsafe.Pointer) {
    val := *(*unsafe.Pointer)(arg)
    null := unsafe.Pointer(uintptr(0))
    *(*unsafe.Pointer)(arg) = null
    AvFree(val)
}


Please note that `AvFree` function needs to be defined which should match the `av_free` function behavior in c++
Note: functions from "unsafe" package require careful treatment, because safety
is not checked while compiling. Use it as a last option if there is no other way. In high-level languages like Go, manual memory freeing is a rare necessity, so check libraries and core packages before using this functionality.


()`:unsafe.Pointer`, av_free`. Working closely``println`(arg)`, val).