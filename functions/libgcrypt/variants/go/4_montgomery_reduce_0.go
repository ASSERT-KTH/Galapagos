package main

func montgomeryReduce(a int32) int16 {
    var t int16
    t = int16(a) * -3327
    t = int16((a - int32(t)*3329) >> 16)
    return t
}


func main(){
    montgomeryReduce(0)
}
