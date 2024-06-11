package main

func int16_t_negative_mask(x int16) int32 {
    return -(x >> 15)
}


func main(){
    int16_t_negative_mask(0)
}
