func fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    out1 *uint32, out2 *uint1,
    arg1 uint1, arg2 uint32,
    arg3 uint32) {
    var x1 uint64
    var x2 uint32
    var x3 uint1
    x1 = uint64((arg1 + arg2) + arg3)
    x2 = uint32(x1 & 0xffffffff)
    x3 = uint1(x1 >> 32)
    *out1 = x2
    *out2 = x3
}
Please note that Go does not explicitly support an unsigned int with 1-bit size type (uint1). You should map this to other round up uint  sizes like uint8.
Here is what it becomes after changing uint1 to uint8.

func fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    out1 *uint32, out2 *uint8,
    arg1 uint8, arg2 uint32,
    arg3 uint32) {
    var x1 uint64
    var x2 uint32
    var x3 uint8
    x1 = uint64((arg1 + arg2) + arg3)
    x2 = uint32(x1 & 0xffffffff)
    x3 = uint8(x1 >> 32)
    *out1 = x2
    *out2 = x3
}
