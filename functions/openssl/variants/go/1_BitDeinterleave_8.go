package main

func BitDeinterleave(Ai uint64) uint64 {
	if Ai%2 == 0 {
		hi := uint32(Ai >> 32)
		lo := uint32(Ai)

		t0 := lo & 0x0000ffff
		t0 |= t0 << 8
		t0 &= 0x00ff00ff
		t0 |= t0 << 4
		t0 &= 0x0f0f0f0f
		t0 |= t0 << 2
		t0 &= 0x33333333
		t0 |= t0 << 1
		t0 &= 0x55555555

		t1 := hi << 16
		t1 |= t1 >> 8
		t1 &= 0xff00ff00
		t1 |= t1 >> 4
		t1 &= 0xf0f0f0f0
		t1 |= t1 >> 2
		t1 &= 0xcccccccc
		t1 |= t1 >> 1
		t1 &= 0xaaaaaaaa

		lo >>= 16
		lo |= lo << 8
		lo &= 0x00ff00ff
		lo |= lo << 4
		lo &= 0x0f0f0f0f
		lo |= lo << 2
		lo &= 0x33333333
		lo |= lo << 1
		lo &= 0x55555555

		hi &= 0xffff0000
		hi |= hi >> 8
		hi &= 0xff00ff00
		hi |= hi >> 4
		hi &= 0xf0f0f0f0
		hi |= hi >> 2
		hi &= 0xcccccccc
		hi |= hi >> 1
		hi &= 0xaaaaaaaa

		Ai = (uint64(hi|lo) << 32) | uint64(t1|t0)
	}
	return Ai
}


func main(){
    BitDeinterleave(0)
}
