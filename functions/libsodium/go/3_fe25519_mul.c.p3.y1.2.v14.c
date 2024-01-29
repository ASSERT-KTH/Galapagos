go
func fe25519_mul(h *[10]int32, f *[10]int32, g *[10]int32) {
    var f0, f1, f2, f3, f4, f5, f6, f7, f8, f9 int32
    var g0, g1, g2, g3, g4, g5, g6, g7, g8, g9 int32
    var g1_19, g2_19, g3_19, g4_19, g5_19, g6_19, g7_19, g8_19, g9_19 int32
    var f1_2 , f3_2 , f5_2 , f7_2 , f9_2  int32
    var f0g0 , f0g1 , f0g2 , f0g3 , f0g4 , f0g5 , f0g6 , f0g7 , f0g8 , f0g9  int64
    var f1g0 , f1g1_2 , f1g2 , f1g3_2 , f1g4 , f1g5_2 , f1g6 , f1g7_2 , f1g8 , f1g9_38 int64
    var f2g0 , f2g1 , f2g2 , f2g3 , f2g4 , f2g5 , f2g6 , f2g7 , f2g8_19 , f2g9_19 int64
    var f3g0 , f3g1_2 , f3g2 , f3g3_2 , f3g4 , f3g5_2 , f3g6 , f3g7_38 , f3g8_19 , f3g9_38 int64
    var f4g0 , f4g1 , f4g2 , f4g3 , f4g4 , f4g5 , f4g6_19 , f4g7_19 , f4g8_19 , f4g9_19 int64
    var f5g0 , f5g1_2 , f5g2 , f5g3_2 , f5g4 , f5g5_38 , f5g6_19 , f5g7_38 , f5g8_19 , f5g9_38 int64
    var f6g0 , f6g1 , f6g2 , f6g3 , f6g4_19 , f6g5_19 , f6g6_19 , f6g7_19 , f6g8_19 , f6g9_19 int64
    var f7g0 , f7g1_2 , f7g2 , f7g3_38 , f7g4_19 , f7g5_38 , f7g6_19 , f7g7_38 , f7g8_19 , f7g9_38 int64
    var f8g0 , f8g1 , f8g2_19 , f8g3_19 , f8g4_19 , f8g5_19 , f8g6_19 , f8g7_19 , f8g8_19 , f8g9_19 int64
    var f9g0 , f9g1_38 , f9g2_19 , f9g3_38 , f9g4_19 , f9g5_38 , f9g6_19 , f9g7_38 , f9g8_19 , f9g9_38 int64
    var h0 , h1 , h2 , h3 , h4 , h5 , h6 , h7 , h8 , h9 int64
    var carry0 , carry1 , carry2 , carry3 , carry4 , carry5 , carry6 , carry7 , carry8 , carry9 int64

    // copy rest of the logic here. Remember to replace each instance of X[Y] with: X.Y, 
	// example: f[0] becomes f.0
	// and *X[Y] with X[Y], example: *h[0] becomes h[0]
}

Note: The above Go version boils down to fundamental difference between C and Go on pointer/array usage. The "*" and "&" are no longer necessary in Go and parenthesis need to be replaced with underscore. Rest can be a wise case by case translation.