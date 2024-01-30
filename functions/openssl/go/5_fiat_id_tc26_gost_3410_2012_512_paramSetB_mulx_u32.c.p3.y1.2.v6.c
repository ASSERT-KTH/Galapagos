Here is the equivalent function in the Go programming language:

go
import "math"

func fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(out1 *uint32, out2 *uint32, arg1 uint32, arg2 uint32) {
    x1 := uint64(arg1) * uint64(arg2)
    x2 := uint32(x1 & math.MaxUint32)
    x3 := uint32(x1 >> 32)
    *out1 = x2
    *out2 = x3
}
