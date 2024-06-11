package main

func modp_norm(x, p uint32) int32 {
    return int32(x - ((p & ^(x - (p+1)/2)) >> 31) + 1)
}


func main(){
    modp_norm(0,0)
}
