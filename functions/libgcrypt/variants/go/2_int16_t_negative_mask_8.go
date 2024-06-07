package main

func int16_t_negative_mask(x int16) int {
    return -int((x >> 15) & 0x1)
}


func main(){
    int16_t_negative_mask(0)
}
