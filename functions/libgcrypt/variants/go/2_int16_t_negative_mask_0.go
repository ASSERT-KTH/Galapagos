package main

func int16_t_negative_mask(x int16) int {
    u := uint16(x)
    return -int(u >> 15)
}


func main(){
    int16_t_negative_mask(0)
}
