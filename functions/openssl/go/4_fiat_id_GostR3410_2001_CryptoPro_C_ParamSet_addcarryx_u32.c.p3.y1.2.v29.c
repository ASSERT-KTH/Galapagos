go
func fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(out1 *uint32, out2 *uint32, arg1 uint32, arg2 uint32, arg3 uint32) {
	var x1 uint64
	var x2 uint32
	var x3 uint32
	x1 = ((uint64(arg1) + uint64(arg2)) + uint64(arg3))
	x2 = uint32(x1 & 0xffffffff)
	x3 = uint32(x1 >> 32)
	*out1 = x2
	*out2 = x3
}

Please note: In Go, there is no built-in type called `uint1`. To represent `fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1` (which likely represents a 1-bit unsigned integer), another type should be used, e.g., `uint32` which is has been used in this translation. If you have a type named `fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1` defined somewhere in your Go code, replace `uint32` in `out2 *uint32` with this type accordingly.