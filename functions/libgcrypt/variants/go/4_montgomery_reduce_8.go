package main

func montgomeryReduce(a int32) int16 {
    t := int16(a - (int32(int16(a)*-3327))*3329)
    return int16(t >> 16)
}


func main(){
    montgomeryReduce(0)
}
