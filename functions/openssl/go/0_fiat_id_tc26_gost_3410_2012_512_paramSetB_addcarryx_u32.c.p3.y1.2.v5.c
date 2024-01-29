go
func fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    out1 *uint32, 
    out2 *bool, 
    arg1 bool, 
    arg2 uint32, 
    arg3 uint32) {
    
    var x1 uint64
    var x2 uint32
    var x3 bool    
    if arg1 {
        x1 = uint64(1)
    } else {
        x1 = uint64(0)
    }
    x1 = (x1 + uint64(arg2) + uint64(arg3))
    x2 = uint32(x1 & 0xffffffff)
    x3 = (x1 >> 32) != 0
    *out1 = x2
    *out2 = x3
}

This version translates the `fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1` a 1 bit integer type functionality from C to Go as `bool` given that Go doesn't have `bool` arithmetic support. When `arg1` is true value of `x1` is taken as `1`, otherwise `0`. Also when high bit value is `1`, `x3` is `true`, otherwise its `false`.