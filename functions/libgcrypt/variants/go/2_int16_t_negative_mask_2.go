package main

func int16_t_negative_mask(x int16) int32 {
    return -int32(bits.RotateLeft16(uint16(x), -15) & 1)
}


func main(){
    int16_t_negative_mask(0)
}
