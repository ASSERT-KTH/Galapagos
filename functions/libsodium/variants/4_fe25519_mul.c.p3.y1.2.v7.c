go
func fe25519_mul(h, f, g [5]uint64) {
	const (
		mask  = uint64(0x7ffffffffffff)
		scale = 19
	)

	var (
		r [5]uint128
		f1_19, f2_19, f3_19, f4_19 uint128
		carry  uint64
	)

	f1_19, f2_19, f3_19, f4_19 = uint128(scale*f[1]), uint128(scale*f[2]), uint128(scale*f[3]), uint128(scale*f[4])

	r[0] = f[0]*g[0] + f1_19*g[4] + f2_19*g[3] + f3_19*g[2] + f4_19*g[1]
	r[1] = f[0]*g[1] + f[1]*g[0] + f2_19*g[4] + f3_19*g[3] + f4_19*g[2]
	r[2] = f[0]*g[2] + f[1]*g[1] + f[2]*g[0] + f3_19*g[4] + f4_19*g[3]
	r[3] = f[0]*g[3] + f[1]*g[2] + f[2]*g[1] + f[3]*g[0] + f[4]*g[4]
	r[4] = f[0]*g[4] + f[1]*g[3] + f[2]*g[2] + f[3]*g[1] + f[4]*g[0]

	for i := 0; i < 4; i++ {
		r[i+1] += uint128(r[i] >> 51)
		h[i] = uint64(r[i] & mask)
	}

	// recalculate the 0-indexed product incorporating the carry, and all following values
	r[0] += uint128(scale * (r[4] >> 51))
	h[4] = uint64(r[4] & mask)

	for i := 0; i < 4; i++ {
		h[i+1] += uint64(r[i] >> 51)
		h[i] &= mask
	}
}

