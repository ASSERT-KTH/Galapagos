go
func fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(out1 *uint32, out2 *uint8, arg1 uint8, arg2 uint32, arg3 uint32) {
	var x1 uint64
	var x2 uint32
	var x3 uint8
	x1 = uint64(arg1) + uint64(arg2) + uint64(arg3)
	x2 = uint32(x1 & 0xffffffff)
	x3 = uint8(x1 >> 32)
	*out1 = x2
	*out2 = x3
}

Please note that Golang does not support custom integer type sizing to retain exactly `fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1` format (which seems to be an 1 bit integer type). Thus, `uint8` is used here, as it is the closest equivalent type among the built-in types in Go. However, this might need some further interpretation on the caller side, to handle the returned value properly. The same thing applies to the `fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1` task type where it's being converted into `uint8` when being passed into the function. The instances that call this function would also need to manage this conversion.