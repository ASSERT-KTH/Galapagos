go
func fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32 (
    out1 *uint32, out2 *uint32,
    arg1 uint32, arg2 uint32, arg3 uint32,) {

    var x1 uint64
    var x2 uint32
    var x3 uint32

    x1 = uint64(arg1) + uint64(arg2) + uint64(arg3)
    x2 = uint32(x1 & 0xffffffff)
    x3 = uint32(x1 >> 32)
    *out1 = x2
    *out2 = x3
}


Considerations:

1. This assumes that the type `fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1`, that is being used in the original C code, is equivalent to the uint32 type in Go. If that's not the case, and it's closer to integer 0 or 1, you might wish to change the data types used.

2. Please notice the way Go handles the constants, `0xffffffff` and Right Shift operation `>>`.

3. Please consult your organization's coding guidelines/style-guide. If strict type conversions are not allowed you may need a different solution.