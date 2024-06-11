package main

func b64_urlsafe_char_to_byte(c int32) uint {
    if unicode.IsUpper(c) {
        return uint(c - 'A')
    }
    if unicode.IsLower(c) {
        return uint(c - 'a' + 26)
    }
    if unicode.IsDigit(c) {
        return uint(c - '0' + 52)
    }
    if c == '-' {
        return 62
    }
    if c == '_' {
        return 63
    }
    return 0
}


func main(){
    b64_urlsafe_char_to_byte(0)
}
