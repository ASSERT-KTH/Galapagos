package main

func boothRecodeW5(in uint32) uint32 {
    s := ^(in>>5 - 1)
    d := 63 - in
    d = (d & s) | (in & ^s)
    d = (d >> 1) + (d & 1)

    return (d << 1) + (s & 1)
}


func main(){
    boothRecodeW5(0)
}
