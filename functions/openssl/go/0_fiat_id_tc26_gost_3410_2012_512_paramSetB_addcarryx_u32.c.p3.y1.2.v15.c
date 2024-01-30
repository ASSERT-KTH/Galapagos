go
func fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(out1 *uint32, out2 *uint32, arg1 uint32, arg2 uint32, arg3 uint32) {
    var x1 uint64
    var x2 uint32
    var x3 uint32
    x1 = uint64(arg1) + uint64(arg2) + uint64(arg3)
    x2 = uint32(x1 & 0xffffffff)
    x3 = uint32(x1 >> 32)
    *out1 = x2
    *out2 = x3
}

Please note that in Go, there is no direct notion of unsigned integer limited to 1 bit which in mentioned C code is designated to ‘fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1’. It's typically replaced by uint8 or bool (or other types on necessary circumstances) based on different conditions. But here we are using uint32 in Go code which represent 4 bytes. So if this function meant to be used in cryptography or similar area (probably, by its name), we should model the original byte behaviour carefully.