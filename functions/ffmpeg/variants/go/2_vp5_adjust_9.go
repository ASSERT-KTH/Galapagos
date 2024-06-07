package main

func vp5_adjust(v int32, t int32) int32 {
    sign := v >> 31
    v = (v ^ sign) - sign
    if v >= 2*t {
        v = 0
    }
    v -= t
    sign2 := v >> 31
    v = (v ^ sign2) - sign2
    return (t - v + sign) - sign
}


func main(){
    vp5_adjust(0,0)
}
