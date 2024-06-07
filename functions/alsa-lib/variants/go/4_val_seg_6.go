package main

func valSeg(val int32) int {
	var r int
	switch {
	case val&(0xff<<8) != 0:
		r += 1
		val >>= 8
		switch {
		case val&(0xf<<4) != 0:
			r += 4
			val >>= 4
			switch {
			case val&(3<<2) != 0:
				r += 2
				val >>= 2
				switch {
				case val&1<<1 != 0:
					r += 1
				}
			}
		}
	default:
		r += 1
	}
	return r
}


func main(){
    valSeg(0)
}
