Go
func is_colored(type indicator_no) bool {
    len := color_indicator[type].len
    s := color_indicator[type].string
    return !(len == 0 ||
            (len == 1 && strings.Compare(s, "0") == 0) ||
            (len == 2 && strings.Compare(s, "00") == 0))
}


For this Go code, please assume that the following are defined somewhere else in your program:

1. `indicator_no` represents some type that you want to use.

2. `color_indicator` is a `map[indicator_no]{ len: int, string: string }` type variable.

Please replace those according to your program.