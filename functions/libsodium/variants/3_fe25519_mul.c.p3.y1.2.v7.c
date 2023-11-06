go
func fe25519_mul(h, f, g [10]int32) {
	var f0 int32 = f[0]
	var f1 int32 = f[1]
	var f2 int32 = f[2]
	var f3 int32 = f[3]
	var f4 int32 = f[4]
	var f5 int32 = f[5]
	var f6 int32 = f[6]
	var f7 int32 = f[7]
	var f8 int32 = f[8]
	var f9 int32 = f[9]

	var g0 int32 = g[0]
	var g1 int32 = g[1]
	var g2 int32 = g[2]
	var g3 int32 = g[3]
	var g4 int32 = g[4]
	var g5 int32 = g[5]
	var g6 int32 = g[6]
	var g7 int32 = g[7]
	var g8 int32 = g[8]
	var g9 int32 = g[9]

	var g1_19 int32 = 19 * g1
	var g2_19 int32 = 19 * g2
	var g3_19 int32 = 19 * g3
	var g4_19 int32 = 19 * g4
	var g5_19 int32 = 19 * g5
	var g6_19 int32 = 19 * g6
	var g7_19 int32 = 19 * g7
	var g8_19 int32 = 19 * g8
	var g9_19 int32 = 19 * g9
	var f1_2  int32 = 2 * f1
	var f3_2  int32 = 2 * f3
	var f5_2  int32 = 2 * f5
	var f7_2  int32 = 2 * f7
	var f9_2  int32 = 2 * f9

	var f0g0 uint64 = uint64(f0) * uint64(g0)
	var f0g1 uint64 = uint64(f0) * uint64(g1)
	var f0g2 uint64 = uint64(f0) * uint64(g2)
	var f0g3 uint64 = uint64(f0) * uint64(g3)
	var f0g4 uint64 = uint64(f0) * uint64(g4)
	var f0g5 uint64 = uint64(f0) * uint64(g5)
	var f0g6 uint64 = uint64(f0) * uint64(g6)
	var f0g7 uint64 = uint64(f0) * uint64(g7)
	var f0g8 uint64 = uint64(f0) * uint64(g8)
	var f0g9 uint64 = uint64(f0) * uint64(g9)
	var f1g0 uint64 = uint64(f1) * uint64(g0)
	var f1g1_2  uint64 = uint64(f1_2) * uint64(g1)
	var f1g2 uint64 = uint64(f1) * uint64(g2)
	var f1g3_2  uint64 = uint64(f1_2) * uint64(g3)
	var f1g4 uint64 = uint64(f1) * uint64(g4)
	var f1g5_2  uint64 = uint64(f1_2) * uint64(g5)
	var f1g6 uint64 = uint64(f1) * uint64(g6)
	var f1g7_2  uint64 = uint64(f1_2) * uint64(g7)
	var f1g8 uint64 = uint64(f1) * uint64(g8)
	var f1g9_38 uint64 = uint64(f1_2) * uint64(g9_19)
	var f2g0 uint64 = uint64(f2) * uint64(g0)
	var f2g1 uint64 = uint64(f2) * uint64(g1)
	var f2g2 uint64 = uint64(f2) * uint64(g2)
	var f2g3 uint64 = uint64(f2) * uint64(g3)
	var f2g4 uint64 = uint64(f2) * uint64(g4)
	var f2g5 uint64 = uint64(f2) * uint64(g5)
	var f2g6 uint64 = uint64(f2) * uint64(g6)
	var f2g7 uint64 = uint64(f2) * uint64(g7)
	var f2g8_19 uint64 = uint64(f2) * uint64(g8_19)
	var f2g9_19 uint64 = uint64(f2) * uint64(g9_19)
	var f3g0 uint64 = uint64(f3) * uint64(g0)
	var f3g1_2   uint64 = uint64(f3_2) * uint64(g1)
	var f3g2 uint64 = uint64(f3) * uint64(g2)
	var f3g3_2   uint64 = uint64(f3_2) * uint64(g3)

//... Continue implementing calculation till the end ... Obtain h0 to h9 next

	var carry0 uint64
	var carry1 uint64
	var carry2 uint64
	var carry3 uint64
	var carry4 uint64
	var carry5 uint64
	var carry6 uint64
	var carry7 uint64
	var carry8 uint64
	var carry9 uint64

	carry0 = (h0 + uint64(1<<25)) >> 26
	h1 += int64(carry0)
	h0 -= carry0 * uint64(1<<26)
	carry4 = (h4 + uint64(1<<25)) >> 26
	h5 += int64(carry4)
	h4 -= carry4 * uint64(1<<26)

    //... Continue obtain/implementation calculation of different carries till the end including lines started with implicit bit shift

	h[0] = int32(h0)
	h[1] = int32(h1)
	h[2] = int32(h2)
	h[3] = int32(h3)
	h[4] = int32(h4)
	h[5] = int32(h5)
	h[6] = int32(h6)
	h[7] = int32(h7)
	h[8] = int32(h8)
	h[9] = int32(h9)
}
