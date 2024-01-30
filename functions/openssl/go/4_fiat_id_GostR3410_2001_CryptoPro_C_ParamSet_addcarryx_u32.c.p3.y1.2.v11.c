go
func fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    out1 *uint32, out2 *uint1, arg1 uint1, arg2 uint32, arg3 uint32) {

    var x1 uint64 = ((uint64(arg1) + uint64(arg2)) + uint64(arg3)) 
    x2 := uint32(x1 & uint64(0xffffffff))  
    x3 := uint1(x1 >> 32) 

    *out1 = x2 
    *out2 = x3
}

The provided code attempts to mimic the C function. Notice though, that Go does not directly supports 1-bit integer types (like the “fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1” type as specified in the signature of your C function). If “fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1” houses integer values beyond the scope of a one-bit integer, it should be replaced with a higher-bit integer type, in order to avoid potential panic due to overflowing in Go. 

Based on your specifications, ‘uint1’ is considered as ‘uint’.  This assumption might lead to incorrect result if ‘uint1’ is not same as ‘uint’ in your environment. Without more context, this is the closest translation we can achieve. You will need to either replace all the `uint1`s with `uint`s (or another fitting type for your values), or you could potentially define a custom `uint1` type in Go. 