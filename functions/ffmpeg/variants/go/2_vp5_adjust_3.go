package main

func vp5_adjust(v int32, t int32) int32 {
    s1 := v >> 31
    absV := v ^ s1 - s1
    if absV >= 2*t {
        absV = 0
    }
    adjusted := absV - t
    s2 := adjusted >> 31
    adjusted = (adjusted ^ s2) - s2
    return (t - adjusted + s1) ^ s1
}


func main(){
    vp5_adjust(0,0)
}
