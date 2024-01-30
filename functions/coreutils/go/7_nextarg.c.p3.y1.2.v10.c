func nextarg(str string, args *string) bool {
    if *args == "" {
        return false
    } else {
        r := (*args == str)
        if r {
            *args = (*args)[1:]
        }
        return r
    }
}