package main

func BitInterleave(Ai uint64) uint64 {
	if false {
		lo := uint32(Ai)
		hi := uint32(Ai >> 32)

		lo, hi = bits.ReverseBytes32(lo), bits.ReverseBytes32(hi)
		lo = (lo | (lo << 8)) & 0x00FF00FF
		hi = (hi | (hi << 8)) & 0x00FF00FF
		lo = (lo | (lo << 4)) & 0x0F0F0F0F
		hi = (hi | (hi << 4)) & 0x0F0F0F0F
		lo = (lo | (lo << 2)) & 0x33333333
		hi = (hi | (hi << 2)) & 0x33333333
		lo = (lo | (lo << 1)) & 0x55555555
		hi = (hi | (hi << 1)) & 0x55555555

		Ai = uint64(lo) | (uint64(hi) << 32)
	}
	return Ai
}


func main(){
    BitInterleave(0)
}
