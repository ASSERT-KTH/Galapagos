go
import "math"

func fiat_id_tc26_gost_3410_2012_512_paramSetB_mulx_u32(out1 *uint32, out2 *uint32, arg1 uint32, arg2 uint32) {
    var x1 uint64
    var x2 uint32
    var x3 uint32
    x1 = uint64(arg1) * uint64(arg2)
    x2 = uint32(x1 & math.MaxUint32)
    x3 = uint32(x1 >> 32)
    *out1 = x2
    *out2 = x3
}

Definitions of the original concepts from the C language have been ported to Go in the following way:
C uint32: uint32 in Go.
C uint64: uint64 in Go.
UINT32_C(0xffffffff): math.MaxUint32 in Go.
uint64_t(x * y): uint64(x) * uint64(y) in Go.
x >> y:right shift operation in Go.
The & and * signs in pointers are used in the same way in Go. As additional notes, package "math" is imported to obtain the value of math.MaxUint32.