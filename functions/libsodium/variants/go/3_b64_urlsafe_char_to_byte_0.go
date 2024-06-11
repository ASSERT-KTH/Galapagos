package main

func b64_urlsafe_char_to_byte(c int32) uint {
    switch {
    case 'A' <= c && c <= 'Z':
        return uint(c - 'A')
    case 'a' <= c && c <= 'z':
        return uint(c - 'a' + 26)
    case '0' <= c && c <= '9':
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
