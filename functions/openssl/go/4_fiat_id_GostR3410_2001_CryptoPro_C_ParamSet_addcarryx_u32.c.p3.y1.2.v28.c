go
package main

import (
  "math/big"
)

func fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    out1 *uint32, out2 *big.Int,
    arg1 big.Int, arg2 uint32,
    arg3 uint32) {
    var x1 uint64
    var x2 uint32
    var x3 *big.Int
    x1 = uint64(arg1.Uint64() + uint64(arg2)) + uint64(arg3)
    x2 = uint32(x1 & 0xffffffff)
    x3 = new(big.Int).Rsh(big.NewInt(int64(x1)), 32)
    *out1 = x2
    *out2 = x3
}

Please note that `fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1` and `UINT32_C` are not standard types in C or Go and they seem to be specific to your project. For this conversion, I used the `uint32` for `fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_uint1` and `big.NewInt` instead of a literal `UINT32_C()`. If they have different actual representations in your specific context, consider substituting the correct one.