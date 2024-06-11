package main

func iec958_parity(data uint32) uint32 {
	data >>= 4
	parity := uint32(0)
	for i := 0; i < 27; i++ {
		if (data & 1) != 0 {
			parity++
		}
		data >>= 1
	}
	return parity & 1
}


func main(){
    iec958_parity(0)
}
