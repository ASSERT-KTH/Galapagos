package main

func mix(c0, c1 int32) int32 {
    blue := (c0 & 0x001F) * 2 + (c1 & 0x001F)
    green := (2 * (c0 & 0x03E0) >> 5) + ((c1 & 0x03E0) >> 5)
    red := (c0 >> 10) * 2 + (c1 >> 10)
    return ((red / 3) * 1024) + (green/3*32) + (blue / 3)
}


func main(){
    mix(0,0)
}
