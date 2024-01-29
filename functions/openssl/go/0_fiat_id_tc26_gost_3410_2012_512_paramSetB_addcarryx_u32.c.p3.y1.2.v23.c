go
//go: noescape
func fiatIDTc26Gost34102012512ParamSetBAddcarryxU32(
	out1 *uint32, 
	out2 *byte, 
	arg1 uint8, 
	arg2 uint32, 
	arg3 uint32) *uint32 {

    var x1 uint64
    var x2 uint32
    var x3 uint8

    x1 = uint64(arg1) + uint64(arg2) + uint64(arg3)
    x2 = uint32(x1 & 0xffffffff)
    x3 = uint8(x1 >> 32)

    *out1 = x2
    *out2 = x3

    return out1
}

Note: Assume that `fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1` can be represented by a `byte` and `uint32_t*` can be represented by a `*uint32` in Go. Also, the original C version of the function returns void, which is not possible in Go functions where it must return at least one output value, in this case we return out1 variable pointer.