package main

func int16_t_negative_mask(x int16) int {
    return -int(uint8(x >> 15))
}


func main(){
    int16_t_negative_mask(0)
}
