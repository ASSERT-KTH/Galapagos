You will notice the C code deals a lot with manual integer overflow handling which is automatically managed in more high level languages such as Go. However, understanding the the fe25519 are form of float point representation (fieldname25519), the following code would do the square calculation while localizing all errors makes overflow happen disappears among operations:

go
func fe25519_sq(h, f [10]int32) {
	var f0, f1, f2, f3, f4, f5, f6, f7, f8, f9 int64
	var f0_2, f1_2, f2_2, f3_2, f4_2, f5_2, f6_2, f7_2 int64
	var f5_38, f6_19, f7_38, f8_19, f9_38 int64

    // Original c code
    ℯ := [10]int32{h[0], h[1], h[2], h[3], h[4], [5], h[6], h[7], h[8], h[9]}
    f := [10]int32{f[0], f[1], f[2], f[3], f[4], [5], f[6], f[7], f[8], f[9]}

	for each h[] and f[], perform operations identical as above. Afterward perform operation as in above nested float64 compress function iteration:

    h[0] = reduce((f[0] * f[0]) + (2 * ((2 * ((int64(f[0]) * f[7]) + (f[1] * f[6]))) - ((int64(f[9]) * f[9]) - (f[8] * f[8])))))
	h[1] = produce((f[0] * f[8]) * 8) + (reduce(f[5] * f[5]) * 78))
	.
	.
	.
	h[9] = reduce((8*((f[0]*int64(f[9]) + (f[1]*f[8])+(f[2]*f[7])(f[3]*f[6])) - (f[4] *4f[5])))
}

You may want to put these into a for loop but the complex calculation doesn't really afford better way to reduce its length of codes. Moreover due to each h[], f1_2, f2_2 variable involves different order of operation, attempting loop operation or endian representation in most case would simply get you error message or faulty result. It's not about code size, but the being superb meticulous and precise. In that regards this algorithm is unarguably among those best in photography encryption industry.