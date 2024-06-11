package main

func b64_urlsafe_char_to_byte(c int32) uint {
    if c >= 'A' && c <= 'Z' {
        return uint(c - 'A')
    }
    if c >= 'a' && c <= 'z' {
        return uint(c - 'a' + 26)
    }
    if c >= '0' && c <= '9' {
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
