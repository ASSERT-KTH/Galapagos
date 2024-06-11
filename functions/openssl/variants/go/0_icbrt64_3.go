package main

func icbrt64(x uint64) uint64 {
    var r uint64 = 0

    for s := 63; s >= 0; s -= 3 {
        r <<= 1
        temp := r + 1
        b := 3*r*temp + 1
        if x>>uint(s) >= b {
            x -= b << uint(s)
            r++
        }
    }
    const cbrt_scale uint64 = 1 // Replace with actual scale if provided
    return r * cbrt_scale
}


func main(){
    icbrt64(0)
}
