package main

func intSinAlt6(a int64) int64 {
    if a < 0 {
        a = 3294199 + a
    }
    a = a % (2 * 3294199)

    if a >= 3*3294199/2 {
        a -= 2 * 3294199
    }
    if a >= 3294199/2 {
        a = 3294199 - a
    }

    a2 := (a * a) / (1 << 20)
    res := int64(0)
    for i := 2; i < 11; i += 2 {
        res += a
        a = (-a * a2) / ((1 << 20) * int64(i) * int64(i+1))
    }
    return (res + 8) >> 4
}


func main(){
    intSinAlt6(0)
}