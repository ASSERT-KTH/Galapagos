package main

func int16_nonzero_mask(x int16) int32 {
	return (int32(^uint32(uint16(x)) >> 31)) * -1
}


func main(){
    int16_nonzero_mask(0)
}