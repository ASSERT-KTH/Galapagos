package main

func montgomeryReduce(a int32) int16 {
    const qinv = 3329
    t := int16(a * -3327)
    return int16((a - int32(t)*qinv) >> 16)
}


func main(){
    montgomeryReduce(0)
}
