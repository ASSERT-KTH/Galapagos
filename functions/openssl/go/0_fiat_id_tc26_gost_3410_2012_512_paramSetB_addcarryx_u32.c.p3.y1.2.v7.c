go
func fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(out1 *uint32, out2 *uint1, arg1 uint1, arg2 uint32, arg3 uint32) {
	var x1 uint64
	var x2 uint32
	var x3 uint1
	x1 = uint64(arg1) + uint64(arg2) + uint64(arg3)
	x2 = uint32(x1 & 0xffffffff)
	x3 = uint1(x1 >> 32)
	*out1 = x2
	*out2 = x3
}


Note: The type `uint1` does not exist in Go. It's an alias for single bit integer used in the original C function presumably. You would need to create or specify a real suitable integral data type or alias to represent single bit integers, which would replace 'uint1' in this Go code. I used 'uint1' as exactly is trying to be similar to the original C code while writing this Go function.