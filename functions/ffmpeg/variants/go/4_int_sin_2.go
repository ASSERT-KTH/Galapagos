package main

func intSin(a int64) int64 {
    if a < 0 {
        a = 3294199 + a
    }
    a %= 6588398

    if a >= 4941298 {
        a -= 6588398
    }
    if a >= 1647099 {
        a = 3294199 - a
    }

    a2 := (a * a) / (1 << 20)
    res := int64(0)
    for i := int64(2); i < 11; i += 2 {
        res += a
        a = -a * a2 / ((1 << 20) * i * (i + 1))
    }
    return (res + 8) >> 4
}


func main(){
    intSin(0)
}
