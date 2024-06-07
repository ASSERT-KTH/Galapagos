package main

func montgomeryReduce(a int32) int16 {
    t := int16(a * -3327)
    result := (a - int32(t)*3329) >> 16
    return int16(result)
}


func main(){
    montgomeryReduce(0)
}
