package main

func b64ByteToURLSafeChar(x uint32) int32 {
    var char int32
    switch {
    case x < 26:
        char = int32(x + 'A')
    case x < 52:
        char = int32(x - 26 + 'a')
    case x < 62:
        char = int32(x - 52 + '0')
    case x == 62:
        char = '-'
    case x == 63:
        char = '_'
    default:
        char = -1
    }
    return char
}


func main(){
    b64ByteToURLSafeChar(0)
}
