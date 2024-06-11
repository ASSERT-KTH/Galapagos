package main

func b64ByteToChar(x uint32) int32 {
    lookup := "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
    return int32(lookup[x])
}


func main(){
    b64ByteToChar(0)
}
