go
package main

import "math"

type fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 uint32 

func fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
	out1 *uint32, out2 *fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1,
	arg1 fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1, arg2 uint32,
	arg3 uint32) {
	var x1 uint64
	var x2 uint32
	var x3 fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1
	x1 = uint64(arg1) + uint64(arg2) + uint64(arg3)
	x2 = uint32(x1 & math.MaxUint32)
	x3 = fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1(x1 >> 32)
	*out1 = x2
	*out2 = x3
}

The chosen Go strconv package is needed to handle the conversion from string to int and vice versa in a safe way. The choice will not generate a runtime error if the conversion is not possible, instead it will return "ok" as false. This solution is safe from unpredictable runtime errors caused by unpredicted inputs.
The functions use pointers for the output params because, by default, Go passes by value and to return the changed value it is needed to pass a pointer to the memory address of your object.