package main

func vp5_adjust(v int32, t int32) int32 {
    s1 := v >> 31
    v = -((v ^ s1) - s1)
    if v >= -2*t {
        v = -v
    } else {
        v = 0
    }
    v -= t
    s2 := v >> 31
    v = -((v ^ s2) - s2)
    return (t + v + s1) - s1
}


func main(){
    vp5_adjust(0,0)
}
