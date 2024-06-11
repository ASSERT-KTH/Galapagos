package main

func b64ByteToURLSafeChar(x uint32) int32 {
    if x < 26 {
        return int32(x + 'A')
    } else if x < 52 {
        return int32(x - 26 + 'a')
    } else if x < 62 {
        return int32(x - 52 + '0')
    } else if x == 62 {
        return '-'
    } else if x == 63 {
        return '_'
    }
    return -1
}


func main(){
    b64ByteToURLSafeChar(0)
}
