package main

func icbrt64(x uint64) uint64 {
    var r uint64 = 0

    for s := 63; s >= 0; s -= 3 {
        r <<= 1
        b := 3*r*(r+1) + 1
        if x>>s >= b {
            x -= b << s
            r++
        }
    }
    const cbrt_scale uint64 = 1 // Assuming cbrt_scale is 1
    return r * cbrt_scale
}


func main(){
    icbrt64(0)
}
