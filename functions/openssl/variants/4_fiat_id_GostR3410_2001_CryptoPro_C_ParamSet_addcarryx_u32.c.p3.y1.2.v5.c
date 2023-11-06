Here is the Go code equivalent to the C function:

go
func fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    out1 *uint32, out2 *fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1, 
    arg1 fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1, arg2 uint32, 
    arg3 uint32) {

    var x1 uint64;
    var x2 uint32;
    var x3 fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1;

    x1 = uint64(arg1) + uint64(arg2) + uint64(arg3)
    x2 = uint32(x1 & 0xffffffff)
    x3 = fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1(x1 >> 32)

    *out1 = x2
    *out2 = x3
}


Before running the code make sure fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1 is defined as a type alias with a base type that fulfills the operation used. It most likely an alias for uint64 , but it also can have a number of different values in Go. And use uint64 at least for arg1.
Also, remember Go does not support operations between different types ithout explicit conversion.
