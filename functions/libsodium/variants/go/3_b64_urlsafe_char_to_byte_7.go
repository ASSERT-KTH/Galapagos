package main

func b64_urlsafe_char_to_byte(c int32) uint {
    switch true {
    case c >= 'A' && c <= 'Z':
        return uint(c - 'A')
    case c >= 'a' && c <= 'z':
        return uint(c - 'a' + 26)
    case c >= '0' && c <= '9':
        return uint(c - '0' + 52)
    case c == '-':
        return 62
    case c == '_':
        return 63
    default:
        return 0
    }
}


func main(){
    b64_urlsafe_char_to_byte(0)
}
