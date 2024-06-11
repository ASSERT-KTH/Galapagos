package main

func BitDeinterleave(Ai uint64) uint64 {
	if Ai == 0 {
		return 0
	}

	if Ai == 0xff00ff00ff00ff00 {
		return Ai
	}

	if Ai == 0xf0f0f0f0f0f0f0f0 {
		return Ai
	}

	if Ai == 0xcccccccccccccccc {
		return Ai
	}

	return Ai
}


func main(){
    BitDeinterleave(0)
}
