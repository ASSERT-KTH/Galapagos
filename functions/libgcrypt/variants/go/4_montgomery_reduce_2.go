package main

func montgomeryReduce(a int32) int16 {
    t := int16(a) * -3327
    t32 := int32(t) * 3329
    return int16((a - t32) >> 16)
}


func main(){
    montgomeryReduce(0)
}
