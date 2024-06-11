package main

func b64ByteToChar(x uint32) int32 {
    switch {
    case x < 26:
        return int32(x + 'A')
    case x < 52:
        return int32(x - 26 + 'a')
    case x < 62:
        return int32(x - 52 + '0')
    case x == 62:
        return '+'
    default:
        return '/'
    }
}


func main(){
    b64ByteToChar(0)
}
