package main

func vp5_adjust(v int32, t int32) int32 {
    s1 := v >> 31
    v = (v ^ s1) + ((~0) & s1)
    if v >= 2*t {
        v = 0
    }
    v -= t
    s2 := v >> 31
    v = (v ^ s2) - s2
    res := t - v + s1
    return res ^ s1
}


func main(){
    vp5_adjust(0,0)
}
