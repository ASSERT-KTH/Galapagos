Here is an equivalent implementation of this function in Golang:

Golang
func fe25519_mul(h *fe25519, f *fe25519, g *fe25519) {
	var f0, f1, f2, f3, f4, f5, f6, f7, f8, f9 int32
	var g0, g1, g2, g3, g4, g5, g6, g7, g8, g9 int32
	var g1_19, g2_19, g3_19, g4_19, g5_19, g6_19, g7_19, g8_19, g9_19 int32
	var f1_2, f3_2, f5_2, f7_2, f9_2 int32

	f0 = (*f)[0]
	f1 = (*f)[1]
	f2 = (*f)[2]
	f3 = (*f)[3]
	f4 = (*f)[4]
	f5 = (*f)[5]
	f6 = (*f)[6]
	f7 = (*f)[7]
	f8 = (*f)[8]
	f9 = (*f)[9]

	g0 = (*g)[0]
	g1 = (*g)[1]
	g2 = (*g)[2]
	g3 = (*g)[3]
	g4 = (*g)[4]
	g5 = (*g)[5]
	g6 = (*g)[6]
	g7 = (*g)[7]
	g8 = (*g)[8]
	g9 = (*g)[9]

	g1_19 = 19 * g1
	g2_19 = 19 * g2
	g3_19 = 19 * g3
	g4_19 = 19 * g4
	g5_19 = 19 * g5
	g6_19 = 19 * g6
	g7_19 = 19 * g7
	g8_19 = 19 * g8
	g9_19 = 19 * g9
	f1_2 = 2 * f1
	f3_2 = 2 * f3
	f5_2 = 2 * f5
	f7_2 = 2 * f7
	f9_2 = 2 * f9

	f0g0 := f0 * int64(g0)
	f0g1 := f0 * int64(g1)

        /* rest of the program... */

	h0 := f0g0 + f1g9_38 + f2g8_19 + f3g7_38 + f4g6_19 + 
        f5g5_38 + f6g4_19 + f7g3_38 + f8g2_19 + f9g1_38
	h1 := f0g1 + f1g0 + f2g9_19 + f3g8_19 + f4g7_19 + 
        f5g6_19 + f6g5_19 + f7g4_19 + f8g3_19 + f9g2_19 
        
        /* rest of the program... */


	carry0 := (h0 + int64(1<<25)) >> 26
	h1 += carry0
	h0 -= carry0 * (uint64)(1<<26)
	carry4 := (h4 + int64(1<<25)) >> 26
	h5 += carry4
	h4 -= carry4 * (uint64)(1<<26)
   
       /* rest of the program... */
   
	h[0] = int32(h0)
	h[1] = int32(h1)
	h[2] = int32(h2)
	/* rest of the program... */
	h[7] = int32(h7)
	h[8] = int32(h8)
	h[9] = int32(h9)
}


Arrays “h”, “f” and “g” here are not specified in function signature due to the lack of specific constriants. Assuming that the input type is a [*]int32 in GOLANG as pointing towards const as we do in C language, where [],
indicates the len of unidentified item list/array (recall it's unspecified specifying whether these are one-dimensional arrays, or of what length, but for this pseudo code golang output an intelligent guess 10 length each has been implied as later code appears to make this assumption.). A pound sign followed by Object defined followed by [] (Object[]), which contains items.