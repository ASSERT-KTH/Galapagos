package main

func vp5_adjust(v int32, t int32) int32 {
    s1 := v >> 31
    v = (v ^ s1) - s1
    flag := v < 2*t
    v *= int32(flag)
    v -= t
    s2 := v >> 31
    v = (v ^ s2) - s2
    return (t - v + s1) ^ s1
}


func main(){
    vp5_adjust(0,0)
}
