go
func fe25519_mul(h *Fe25519, f, g *Fe25519) {
	f0 := int32(f[0])
	f1 := int32(f[1])
	f2 := int32(f[2])
	f3 := int32(f[3])
	f4 := int32(f[4])
	f5 := int32(f[5])
	f6 := int32(f[6])
	f7 := int32(f[7])
	f8 := int32(f[8])
	f9 := int32(f[9])

	g0 := int32(g[0])
	g1 := int32(g[1])
	g2 := int32(g[2])
	g3 := int32(g[3])
	g4 := int32(g[4])
	g5 := int32(g[5])
	g6 := int32(g[6])
	g7 := int32(g[7])
	g8 := int32(g[8])
	g9 := int32(g[9])

	g1_19 := int32(19 * g1) 
	g2_19 := int32(19 * g2) 
	g3_19 := int32(19 * g3)
	g4_19 := int32(19 * g4)
	g5_19 := int32(19 * g5)
	g6_19 := int32(19 * g6)
	g7_19 := int32(19 * g7)
	g8_19 := int32(19 * g8)
	g9_19 := int32(19 * g9)
	f1_2  := int32(2 * f1)
	f3_2  := int32(2 * f3)
	f5_2  := int32(2 * f5)
	f7_2  := int32(2 * f7)
	f9_2  := int32(2 * f9)

	f0g0    := int64(f0) * int64(g0)
	f0g1    := int64(f0) * int64(g1)
	f0g2    := int64(f0) * int64(g2)
	// ... you create variables using given algorithm
    // ...

	carry0 := bitAndRsh1Lsh((h0 + (1<<25)), 26, 1, 26)
    h1 += carry0
    h0 -= carry0 * (1 << 26)
    // ... do the same thing for carry variable ...
    // ...

	h[0] = f0
	h[1] = f1
	// remaining indexes of h array remains the same...
	h[9] = f9
}

func bitAndRsh1Lsh(val, fam1, fam2, fbm1 float64) int64 {
	// This function replaces the >> << operators 
	return int64(val) & (int64(fam1) >> int64(fbm1)) << int64(fam2)
}
