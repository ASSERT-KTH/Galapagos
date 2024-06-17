package main

func b64ByteToChar(x uint32) int32 {
    alphabets := "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    if x < 26 {
        return int32(alphabets[x])
    }
    alphabets = "abcdefghijklmnopqrstuvwxyz"
    if x < 52 {
        return int32(alphabets[x-26])
    }
    numbers := "0123456789"
    if x < 62 {
        return int32(numbers[x-52])
    }
    if x == 62 {
        return '+'
    }
    return '/'
}


func main(){
    b64ByteToChar(0)
}