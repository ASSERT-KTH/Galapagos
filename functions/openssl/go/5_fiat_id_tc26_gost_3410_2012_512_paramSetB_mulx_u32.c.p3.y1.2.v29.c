Here is an approximation of the equivalent function in Go:

Go
// Due to Go's reduced support for pointer manipulation, 
// the code is slightly modified. Instead of using pointers, 
// it returns two valid `uint32`.
func fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(arg1 uint32, arg2 uint32) (uint32, uint32) {
    var x1 uint64
    var x2 uint32
    var x3 uint32
    x1 = uint64(arg1) * uint64(arg2)
    x2 = uint32(x1 & 0xffffffff)
    x3 = uint32(x1 >> 32)
    return x2, x3
}

This will replicate the software arithmetic function. Return statement is used here because Golang does not support pointer the way C does. On another note, masking operation(`0xffffffff`) in this context might not be functionally relevant since x1's initial high 32 bits are a product of max-uint32 values and their result always fits inside low 32 bits.