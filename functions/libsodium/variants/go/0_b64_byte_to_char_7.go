package main

func b64ByteToChar(x uint32) int32 {
    const base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
    return int32(base64Chars[x])
}


func main(){
    b64ByteToChar(0)
}
