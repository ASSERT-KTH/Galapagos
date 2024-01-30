Go
func fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    out1 *uint32, out2 *uint1,
    arg1 uint32, arg2 uint1, arg3 uint32) {
    var x1 uint64
    var x2 uint32
    var x3 uint1
    x1 = ((uint64(arg1) + uint64(arg2)) + uint64(arg3))
    x2 = uint32(x1 & 0xffffffff)
    x3 = uint1(x1 >> 32)
    *out1 = x2
    *out2 = x3
}

Please note that Go doesn't actually natively support "uint1", which is a type that holds only 0 or 1. I've used "uint1" to maintain consistency with the original question, but remember this type doesn't natively exist in Go -- usually bool, byte or a larger standard integer type would be used depending on context.