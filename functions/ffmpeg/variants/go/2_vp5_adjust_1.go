package main

func vp5_adjust(v int32, t int32) int32 {
    s1 := v >> 31
    if s1 != 0 {
        v = -v
    }
    if v >= 2*t {
        v = 0
    }
    v -= t
    s2 := v >> 31
    if s2 != 0 {
        v = -v
    }
    v = t - v
    if s1 != 0 {
        v = -v
    }
    return v
}


func main(){
    vp5_adjust(0,0)
}
