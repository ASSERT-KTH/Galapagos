package main

func b64_urlsafe_char_to_byte(c int32) uint {
    var result uint
    switch {
    case c >= 'A' && c <= 'Z':
        result = uint(c - 'A')
    case c >= 'a' && c <= 'z':
        result = uint(c - 'a' + 26)
    case c >= '0' && c <= '9':
        result = uint(c - '0' + 52)
    case c == '-':
        result = 62
    case c == '_':
        result = 63
    default:
        result = 0
    }
    return result
}


func main(){
    b64_urlsafe_char_to_byte(0)
}
