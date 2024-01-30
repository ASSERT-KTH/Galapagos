go
package main

import "math"

func fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(out1 *uint32, out2 *uint8, arg1 uint8, arg2 uint32, arg3 uint32) {
    var x1 uint64
    var x2 uint32
    var x3 uint8
    x1 = uint64(arg1) + uint64(arg2) + uint64(arg3)
    x2 = uint32(x1 & math.MaxUint32)
    x3 = uint8(x1 >> 32)
    *out1 = x2
    *out2 = x3
}


Here are the reasons for certain transformations:

1. In Go language there are no predefined types named as `fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1`, so as per C semantics, `uint8` type is used instead for `fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1` to occupy single byte of space. We assume this because in the original C code `fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1` acts as boolean, which holds a value of 0 or 1 in most cases.

2. Similarly, a semantic alias created for large integer operations on fixed bit-width numbers in crypto math usage `UINT32_C()` has no equivalent in Go language. So we use `math.MaxUint32` which provides a constant in Go that accommodates exactly that - the maximum value for a `uint32`. 

3. In place of static keyword we've simply omitted it because Go does not have an explicit keyword for "file-private" visibility. It has package private visibility, where anything non-exported (that is, identifiers starting with a lower-case letter) are visible throughout the same package but not outside.
4. Packet declaration (`package main`) added for Go.

Also worth to mention that Go doesn't support default values so all parameters will have to be explicitly passed when calling this function.