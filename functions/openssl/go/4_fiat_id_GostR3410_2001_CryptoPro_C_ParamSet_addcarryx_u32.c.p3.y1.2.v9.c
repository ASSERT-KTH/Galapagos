go
func fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    out1 *uint32, out2 *int, arg1 int, arg2 uint32, arg3 uint32) {
    var x1 uint64
    var x2 uint32
    var x3 int
    x1 = uint64(arg1) + uint64(arg2) + uint64(arg3)
    x2 = uint32(x1 & 0xffffffff)
    x3 = int(x1 >> 32)
    *out1 = x2
    *out2 = x3
}


Please note fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1, which is a uint with only two value possible {0, 1} we can relate that with a boolean variable but as boolean type variables are not allowed in go in numeric operations so I used "int" instead.


