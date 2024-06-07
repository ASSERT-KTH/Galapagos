package main

func int16_t_negative_mask(x int16) int {
    return -(int(uint16(x) >> 15) & 1)
}


func main(){
    int16_t_negative_mask(0)
}
