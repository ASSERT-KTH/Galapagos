package main

func b64ByteToURLSafeChar(x uint32) int32 {
    switch {
    case x < 26:
        return int32(x + 'A')
    case x < 52:
        return int32(x - 26 + 'a')
    case x < 62:
        return int32(x - 52 + '0')
    case x == 62:
        return int32('-')
    case x == 63:
        return int32('_')
    default:
        return -1
    }
}


func main(){
    b64ByteToURLSafeChar(0)
}
