package main

func iec958_parity(data uint32) uint32 {
	data >>= 4
	parity := 0
	for bit := 4; bit <= 30; bit++ {
		if (data & 1) != 0 {
			parity++
		}
		data >>= 1
	}
	return uint32(parity % 2)
}


func main(){
    iec958_parity(0)
}