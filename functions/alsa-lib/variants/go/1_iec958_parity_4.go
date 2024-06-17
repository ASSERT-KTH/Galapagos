package main

func iec958_parity(data uint32) uint32 {
	data >>= 4
	parity := uint32(0)
	for bit := 4; bit <= 30; bit++ {
		parity ^= data & 1
		data >>= 1
	}
	return parity
}


func main(){
    iec958_parity(0)
}