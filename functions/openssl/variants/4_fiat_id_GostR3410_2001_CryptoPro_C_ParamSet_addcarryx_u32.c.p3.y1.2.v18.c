func fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(out1 *uint32, out2 *uint32, arg1, arg2, arg3 uint32) {
    var x1 uint64
    var x2 uint32
    var x3 uint32
    x1 = uint64(arg1) + uint64(arg2) + uint64(arg3)
    x2 = uint32(x1 & 0xffffffff)
    x3 = uint32(x1 >> 32)
    *out1 = x2
    *out2 = x3
}