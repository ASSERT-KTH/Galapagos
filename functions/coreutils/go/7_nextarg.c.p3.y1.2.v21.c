There is no pointer arithmetic in Go, and also Go deals differently in string comparison and in passing variables between functions. Here is the equivalent function code in Go.

import "strings"

func nextarg(args *string, str string) bool {
    if args == nil
        return false
    }

    r := strings.Compare(*args, str) == 0
    if r {
        *args = string([]rune(*args)[1:])
    }
    
    return r
}