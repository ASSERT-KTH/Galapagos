package main

func b64ByteToChar(x uint32) int32 {
    if x < 26 {
        return int32(x + 'A')
    } else if x < 52 {
        return int32(x - 26 + 'a')
    } else if x < 62 {
        return int32(x - 52 + '0')
    } else if x == 62 {
        return '+'
    }
    return '/'
}


func main(){
    b64ByteToChar(0)
}
