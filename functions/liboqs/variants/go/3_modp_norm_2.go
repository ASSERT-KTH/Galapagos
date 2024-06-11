package main

func modp_norm(x, p uint32) int32 {
    return int32(x - (uint32(int32(p) * int32(((x-((p+1)>>1))>>31)-1))))
}


func main(){
    modp_norm(0,0)
}
