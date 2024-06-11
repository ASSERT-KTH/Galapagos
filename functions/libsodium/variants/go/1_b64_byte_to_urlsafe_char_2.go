package main

func b64ByteToURLSafeChar(x uint32) int32 {
    if x <= 63 {
        if x < 26 {
            return int32(x + 'A')
        } else if x < 52 {
            return int32(x + 'a' - 26)
        } else if x < 62 {
            return int32(x + '0' - 52)
        } else if x == 62 {
            return '-'
        } else {
            return '_'
        }
    }
    return -1
}


func main(){
    b64ByteToURLSafeChar(0)
}
