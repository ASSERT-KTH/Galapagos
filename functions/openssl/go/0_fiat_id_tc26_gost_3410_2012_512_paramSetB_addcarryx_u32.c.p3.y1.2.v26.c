Go
func fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(out1 *uint32, out2 *uint32, arg1 uint32, arg2 uint32, arg3 uint32) {
    var x1 uint64
    var x2 uint32
    var x3 uint32
    x1 = (uint64(arg1) + uint64(arg2) + uint64(arg3))
    x2 = uint32(x1 & 0xffffffff)
    x3 = uint32(x1 >> 32)
    *out1 = x2
    *out2 = x3
}

Considerations:

- In Go, there are no unsized integers, so we assume `fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1` is a `uint32`.
- Go does not support constant expressions like `UINT32_C`, we simply use a hexadecimal constant
`0xffffffff`. Changing this depends on the original function's intention which is not completely clear in the question.
- In Go there is no direct analogous to `static` functions from C. Therefore, the exact intended visibility/concealment of the function might not be interpreted correctly in this situation. This should be controlled through package exposure in a real-world scenario.
- It's normally good practice in Go to provide a bit more context about the function purpose and behavior. Agreements about error handling, performance, limitations, test coverage, and more are commonly expressed in documentation comments on top of exported symbols, which this problem forbids.
- This interpretation assumes original C code behavior is expected as a strictly followed guideline, therefore important Go idioms might be left aside in order to comply with the problem conditions. It still might be a good starting point for further Go idiomatic improvements now that the function is in Go.