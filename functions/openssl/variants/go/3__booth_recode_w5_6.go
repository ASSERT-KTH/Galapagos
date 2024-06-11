package main

func boothRecodeW5(in uint32) uint32 {
    s := ^(uint32((int32(in) >> 5) - 1))
    if s == 0 {
        return 0
    }
    d := 63 - in
    d = (d >> 1) + (d & 1)

    return (d << 1) + (s & 1)
}


func main(){
    boothRecodeW5(0)
}
