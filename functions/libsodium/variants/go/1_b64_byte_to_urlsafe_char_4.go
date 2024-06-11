package main

func b64ByteToURLSafeChar(x uint32) int32 {
    table := "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_"
    if x >= 64 {
        return -1
    }
    return int32(table[x])
}


func main(){
    b64ByteToURLSafeChar(0)
}
