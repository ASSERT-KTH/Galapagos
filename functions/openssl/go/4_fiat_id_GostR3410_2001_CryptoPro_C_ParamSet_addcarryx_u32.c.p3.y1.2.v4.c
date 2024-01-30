go
import (
    "math"
    "math/big"
)

func fiat_id_GostR3410_2001_CryptoPro_C_ParamSet_addcarryx_u32(
    out1 *uint32, out2 *uint1,
    arg1 uint1, arg2 uint32,
    arg3 uint32) {
    var x1 uint64
    var x2 uint32
    var x3 uint1
    x1 = ((uint64)(arg1) + (uint64)(arg2) + (uint64)(arg3))
    x2 = uint32(x1 & math.MaxUint32)
    x3 = uint1(x1 >> 32)
    *out1 = x2
    *out2 = x3
}


Please note that in the Go standard library, there is no concept for a 1-bit integer. Therefore, the Go version uses a normal `uint` and you should ensure that it contains only a 0 or 1. In the real-world development, it might be suggested to replace it with boolean values.